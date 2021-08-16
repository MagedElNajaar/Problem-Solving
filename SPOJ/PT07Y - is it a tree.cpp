#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int node,edge,u,v;
vector < vector < int > > adj;
bool vis[10009];

void addEdge(int u, int v){
    adj[u].push_back(v);
}

bool BFS(int u){
    queue <int> Q;
    Q.push(u);
    vis[u] = true;
    int cnt = 0;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        
        for(int i=0;i < adj[u].size();i++){
            int v = adj[u][i];
            if(!vis[v]){
                vis[v] = true;
                Q.push(v);
            }else
                return false;
        }
        ++cnt;
    }
    if(cnt != node) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>node>>edge;
    adj.resize(node+9);
    memset(vis,0,sizeof(vis));
    
    for(int i = 0;i<edge;i++){
        cin >> u >> v;
        addEdge(u, v);
    }
    cout << (BFS(1) ? "YES" : "NO" ) << endl;
    return 0;
}
