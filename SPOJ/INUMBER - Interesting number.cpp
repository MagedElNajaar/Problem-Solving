#include <iostream>
using namespace std;
int t,n;
const int N = 1e3 + 9;
struct state{
    int d,m,rem,S;
}Q[N*N];
int sz;
int vis[N][N],vid;

void BFS(){
    int fnt = 0;
    sz = 0;
    vid++;
    for(int digit = 1;digit <= min(9,n);digit++){
        int m = digit % n;
        int rem = n - digit;
        Q[sz++] = {digit,m,rem,-1};
        if(!m && !rem) return;
        vis[m][rem] = vid;

    }

    while(fnt < sz){
        state f = Q[fnt++];
        for(int digit = 0; digit <= min(f.rem,9);digit++){
            int nm = (f.m * 10 + digit) % n;
            int nrem = f.rem - digit;
            if(vis[nm][nrem] == vid) continue;
            vis[nm][nrem] = vid;
            Q[sz++] = {digit,nm,nrem,fnt - 1};
            if(!nm && !nrem) return;
        }
    }
}

void print(int idx = sz - 1){
    if(idx == -1) return;
    print(Q[idx].S);
    cout<<Q[idx].d ;
}

int main() {
    cin>>t;
    while(t--){
        cin>>n;
        BFS();
        print();
        puts("");
    }
    return 0;
}
