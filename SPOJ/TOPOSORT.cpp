#include <bits/stdc++.h>
using namespace std;
int cnt[10001];
int nodes,edges;
vector <int> adj[10001];
vector <int> ans;
set<int>S; //For Tasks Can I do now

int main() {
    cin >> nodes >> edges;
    for(int i=0;i<edges;i++){
        int from,to;
        cin >> from >> to;
        adj[from].push_back(to); //AddEdge
        cnt[to]++;
    }
    for(int i=1;i<=nodes;i++){
        if(!cnt[i])
            S.insert(i);
    }
    
    while(S.size()){
        int u = *S.begin();
        S.erase(S.begin());
        ans.push_back(u);
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            cnt[v]--;
            if(!cnt[v])
                S.insert(v);
        }
    }  
    
    if(ans.size()!= nodes)
        cout << "Sandro fails." << endl;
    else{
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
    }
    return 0;
}
