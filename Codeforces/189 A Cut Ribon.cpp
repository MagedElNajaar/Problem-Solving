#include <bits/stdc++.h>
using namespace std;
#define NEG -10000000

int n,a,b,c;
int memo[4001];

int solve(int n){
    if(n<0) return NEG;
    if(n==0) return 0;
    if(memo[n] != -1) return memo[n];
    int Op1 = solve(n-a) + 1;
    int Op2 = solve(n-b) + 1;
    int Op3 = solve(n-c) + 1;
    
    return memo[n] = max(max(Op1,Op2),Op3);

}

int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> a >> b >> c;
    cout << solve(n) << endl;
    return 0;
}
