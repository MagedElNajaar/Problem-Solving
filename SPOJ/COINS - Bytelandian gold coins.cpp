#include <bits/stdc++.h>
using namespace std;

int n;
map<int,long long> memo;

long long solve(int n){
    if(n==0) return 0;
    if(memo[n] != 0) return memo[n];
    long long opt = solve(n/2) + solve(n/3) + solve(n/4);
    return memo[n] = max(opt,(long long)n);
}
int main(){
    
    while(cin>>n)
        cout << solve(n) << endl;
}
