#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int N = 1e6 + 10;


int nodes, edges;
long long dis[N];

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
            }
        }
    }
}

    
int main(){
    
    int ex,ti;
    cin>> nodes >> ex >> ti >> edges;
    //memset ( dis , 0x3f , sizeof (dis[0])*nodes);
    fill(dis, dis + N, (long long)1e18);
    while(edges--){
        int from, to, cost;
        cin>> from >> to >> cost;
        from--; to--;
        adj[to].push_back(make_pair(from, cost));
    }
    

    Dijkstra(ex - 1); //source node
    int ans = 0;
    for(int i=0;i<nodes;i++)
        if(dis[i] != (long long)1e18 && dis[i] <= ti)ans++;
        cout << ans;
}
