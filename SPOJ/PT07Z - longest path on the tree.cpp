#include <iostream>
#include <vector>

using namespace std;
int node,u,v;
vector< vector <int> > adj;
bool vis[10009];
int ans = 0;

int DFS(int u){
    int prev_longest_path, sub1 = -1 ,sub2 = -1;
    vis[u] = true;
    for(int i=0;i < adj[u].size();i++){
        int v = adj[u][i];
        if(!vis[v]){
            prev_longest_path = DFS(v);
            if(prev_longest_path >= sub1){
                sub2 = sub1;
                sub1 = prev_longest_path;
            }else if(prev_longest_path > sub2){
                sub2 = prev_longest_path;
            }
        }
    }
    ans = max(ans, sub1 + sub2 + 2);
    return sub1 + 1;
}


int main() {
    cin>>node;
    adj.clear();
    adj.resize(node+9);
    
    for(int i=0;i<node-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    DFS(1);
    cout << ans << endl;
    
    return 0;
}
