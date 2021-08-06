#include <bits/stdc++.h>
using namespace std;

int k1,k2;
int memo[101][101][11][2];
int solve(int n1,int n2,int k,bool Horse){
    if(n1 == 0 && n2 == 0) return 1;
    if(n1 < 0 || n2 < 0) return 0;
    if(memo[n1][n2][k][Horse] != -1)
        return memo[n1][n2][k][Horse];
    int op1 = 0, op2 = 0;
    
    if(Horse){
        op1 = solve(n1 - 1,n2,1,0);
        if(k + 1 <= k2)
            op2 = solve(n1,n2 - 1,k + 1,1);
    }else{
        if(k + 1 <= k1)
            op1 = solve(n1 - 1,n2,k + 1,0);
        op2 = solve(n1,n2 - 1,1,1);
    }
    return memo[n1][n2][k][Horse] = (op1+op2) % 100000000;
}

int main() {
    memset(memo,-1,sizeof memo);
    int n1,n2;
    cin>>n1>>n2>>k1>>k2;
    cout<<solve(n1,n2,0,0)<<endl;
    return 0;
}
