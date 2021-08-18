#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int N = 1e6 + 10;

int nodes,edges;
vector < pair < int, int > > adj[N];
long long dis[N];
int Parent[N];

void addBiEdge(int &f,int &t,int &c){
    adj[f].push_back(make_pair(t, c));
    adj[t].push_back(make_pair(f, c));
}


void Dijkstra(int src){
    dis[src] = 0;
    priority_queue< pair < long long, int > > pq;
    pq.push(make_pair(0,src));
    
    while(pq.size()){
        int u;
        long long src_cost;
        u = pq.top().second;
        src_cost = -pq.top().first;
        pq.pop();
        
        if(src_cost != dis[u]) continue;
        
        for(auto Edge : adj[u]){
            int v = Edge.first;
            long long Cst_Edge = Edge.second;
            
            if(dis[v] > src_cost + Cst_Edge){
                dis[v] = src_cost + Cst_Edge;
                pq.push(make_pair(-dis[v], v));
                Parent[v] = u;
            }
        }
    }
}

void Dijkstra_Path(int node){
    if(node == -1) return;
    Dijkstra_Path(Parent[node]);
    cout << node + 1 << " ";
}

int main(){
    cin >> nodes >> edges;
    //memset(dis, 0x3f, sizeof (dis[0])*nodes);
    fill(dis,dis + N,(long long)1e18);
    while(edges--){
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        addBiEdge(from, to, cost);
    }
    Parent[0] = -1;
    Dijkstra(0);
    //cout << dis[nodes - 1] << endl;
    if(dis[nodes - 1] == (long long)1e18)
        cout << -1 << endl;
    else
        Dijkstra_Path(nodes - 1);
    
}

 
