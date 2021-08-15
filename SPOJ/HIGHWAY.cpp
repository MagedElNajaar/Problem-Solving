#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int N = 1e6 + 10;


int nodes, edges;
long long dis[N];
int path[N];
vector<pair<int,int>> adj[N];

void Dijkstra (int src){
    dis[src] = 0;
    
    priority_queue <pair<long long,int>> pq;
    pq.push(make_pair(0, src));
    
    while (pq.size()){
        int u;
        long long best_cst;
        best_cst = -pq.top().first;
        u = pq.top().second;
        pq.pop();

        if (best_cst != dis[u]) continue;
        
        for (auto edge : adj[u]){
            int v = edge.first;
            int c_edge = edge.second;
            if (dis[v] > best_cst + c_edge){
                dis[v] = best_cst + c_edge;
                pq.push(make_pair(-dis[v], v));
                path[v] = u;
        }
    }
}
}
void Dijkstra_Path(int node){
    if(node == -1) return;
    Dijkstra_Path(path[node]);
    cout<< node + 1 <<" ";
}
    
int main(){
    int t;
    cin>>t;
    while(t--){
       
    int st,ed;
    cin>> nodes >> edges >> st >> ed;
        for(int i=0;i<nodes;i++) adj[i].clear();
        //memset ( dis , 0x3f , sizeof (dis[0])*nodes);
    fill(dis, dis + N, (long long)1e18);
    
    while(edges--){
        int from, to, cost;
        cin>> from >> to >> cost;
        from--; to--;
        adj[from].push_back(make_pair(to, cost));
        adj[to].push_back(make_pair(from, cost));
    }
    
    path[0] = -1;
    Dijkstra(st - 1); //source node
    
    if(dis[ed-1] == (long long)1e18)
        cout<<"NONE"<<endl;
    else
        cout << dis[ed-1] << endl;
    }
}
