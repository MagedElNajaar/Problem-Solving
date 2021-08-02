#include <bits/stdc++.h>
using namespace std;
int sze[2001],value[2001];
int items;
int memo[2001][2001];

int solve(int sz,int idx){
    if(idx == items) return 0;
    if(memo[sz][idx] != -1) return memo[sz][idx];
    int op1,op2 = 0;
    op1 = solve(sz,idx + 1);
    
    if(sze[idx] <= sz){
        op2 = solve(sz-sze[idx], idx + 1) + value[idx];
    }
        return memo[sz][idx] = max(op1,op2);
}

int main() {
    memset(memo,-1,sizeof memo);
    int sz;
    cin>>sz>>items;
    for(int i = 0; i < items ; i++){
        cin>>sze[i]>>value[i];
    }
    cout << solve(sz,0) << endl;
    return 0;
}
