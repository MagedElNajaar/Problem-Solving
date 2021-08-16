#include <bits/stdc++.h>

using namespace std;
string a,b;
int memo[10][10];

int solve(int i,int j){
    if(i==a.size() || j==b.size()) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(a[i]==b[j]){
        return memo[i][j] = solve(i+1,j+1) + 1;
    }
    int Op1 = solve(i,j+1);
    int Op2 = solve(i+1,j);
    
    return memo[i][j] = max(Op1,Op2);
}


int main() {
    memset(memo, -1, sizeof memo);
    cin>>a>>b;
    cout << solve(0,0) << endl;
}
