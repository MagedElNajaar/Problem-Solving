#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

const int N = 1e6 + 10;
int n,m;
vector < pair < pair < int,int > , int > > adj;
int cost[N];
bool Bellman_Ford(int src){
    cost[src] = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j < m ;j++){
            int u = adj[j].first.first;
            int v = adj[j].first.second;
            int c = adj[j].second;
            cost[v] = min(cost[v], cost[u] + c);
        }
    }
    for(int j = 0;j < m ;j++){
        int u = adj[j].first.first;
        int v = adj[j].first.second;
        int c = adj[j].second;
        if(cost[u] + c < cost[v]) return 0;
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        adj.clear();
        memset(cost, 0x3f, sizeof cost);
        for(int i=0;i<m;i++){
            int u,v,c;
            cin>>u>>v>>c;
            adj.push_back({{u,v},c});
        }
        int src  = 0;
        
        if(!Bellman_Ford(src)){
            cout << "possible" << endl;
        }
        else
            cout << "not possible" << endl;
    }
}

