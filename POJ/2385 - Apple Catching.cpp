#include <bits/stdc++.h>
using namespace std;

int t;
int arr[1001];
int memo[1001][3][31];
int solve(int idx,int tree,int m){
    if(idx == t) return 0;
    if(memo[idx][tree][m] != -1) return memo[idx][tree][m];
    if(arr[idx] == tree) return 1 + solve(idx + 1,tree,m);
    else{
        int op1 = solve(idx + 1, tree, m);
        int op2 = 0;
        if(m)
            op2 = 1 + solve(idx + 1, 3 - tree, m - 1);
        return memo[idx][tree][m] = max(op1,op2);
        
    }
    
}

int main() {
    int m;
    memset(memo,-1,sizeof memo);
    cin>>t>>m;
    for(int i = 0;i<t;i++){
        cin>>arr[i];
    }
    cout << solve(0,1,m) << endl;
    return 0;
}
