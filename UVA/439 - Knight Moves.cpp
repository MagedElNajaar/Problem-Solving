#include <iostream>
#include <queue>
using namespace std;

int dis[8][8];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

bool isValid(int r,int c){
    return (r >= 0 && c >=0 && r < 8 && c < 8);
}

int BFS(int sr,int sc,int tr,int tc){
    memset(dis, -1, sizeof(dis));
    dis[sr][sc] = 0; //Dis to S = 0
    queue<int>Q;
    Q.push(sr);
    Q.push(sc);
    while (!Q.empty()) {
        int r = Q.front();
        Q.pop();
        int c = Q.front();
        Q.pop();
        if(r == tr && c == tc)
            return dis[r][c];
        
        for(int i=0;i<8;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(!isValid(nr, nc)) continue;
            if(dis[nr][nc] == -1){
                dis[nr][nc] = dis[r][c] + 1;
                Q.push(nr);
                Q.push(nc);
            }
        }
    }
    return -1;
}

int main() {
    string s1,s2;
    while(cin>>s1>>s2){
        int move = BFS(s1[1] - '1',s1[0] - 'a',s2[1] - '1',s2[0] - 'a');
        cout << "To get from "<<s1<<" to "<<s2<<" takes "<<move<< " knight moves." << endl;
    }
    return 0;
}

