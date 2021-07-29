#include <iostream>
#include <set>
#include <queue>
#include <map>
using namespace std;
set <pair<int,int>> pts;

int main() {
    int x1,y1,x2,y2,n;
    cin>>x1>>y1>>x2>>y2>>n;
    
    for(int i=0;i<n;i++){
        int r,a,b;
        cin>>r>>a>>b;
        
        //Create Graph Points
        for(int row_cell=a;row_cell<=b;row_cell++){
            pts.insert({r,row_cell});
        }
    }
    
    int dx[] = { 1, 0, -1, 0, -1, 1, -1, 1 };
    int dy[] = { 0, 1, 0, -1, -1, 1, 1, -1 };
    
    
    map < pair <int,int>, int> len;
    
    //BFS
    queue < pair <int,int> > q;
    pair <int, int > S = {x1,y1};
    q.push(S);
    len[S] = 0;

    while(!q.empty()){

        pair <int,int> u = q.front();
        q.pop();
        
        //For every Neighbor
        for(int i = 0; i < 8; i++){
            int nx = u.first + dx[i];
            int ny = u.second + dy[i];
            pair <int,int> new_Point = {nx,ny};
            
            //Point Doesn't Exist Or Already Reached
            if(pts.count(new_Point) == 0 || len[new_Point] != 0)
                continue;
        
            q.push(new_Point);
            len[new_Point] = len[u] + 1;
            
            if(new_Point.first == x2 && new_Point.second == y2){
                cout << len[new_Point];
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
