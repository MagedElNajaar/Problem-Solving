#include <bits/stdc++.h>

using namespace std;

int n;
long long coin[10005];
long long DP[10005];

long long solve(int idx){
    if(idx >= n) return 0;
    if(DP[idx] != -1) return DP[idx];
    return DP[idx] = max(solve(idx + 1) ,solve(idx + 2) + coin[idx]);
    //if you choose the idx monster's coins, you cannot choose the next one.
    //So you will move to the idx + 2 monster.
    //if you donot choose the idx monster's coins you still have a chance
    //to choose the idx + 1 monster's coins.
    //So You will move to idx + 1 monster
}

int main() {
    int t;
    cin>>t;
    for(int j = 1;j<= t;j++){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>coin[i];
        memset(DP,-1,sizeof DP);
        cout << "Case " << j << ": " << solve(0) << endl;
    }
    return 0;
}
