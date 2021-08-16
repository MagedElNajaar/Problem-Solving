#include <iostream>
using namespace std;
string a,b;
int memo[2001][2001];

int solve(int i,int j){
    if(i == a.size())
        return b.size() - j;
    if(j == b.size())
        return a.size() - i;
    
    if(memo[i][j] != -1) return memo[i][j];
    if(a[i] == b[j]) return memo[i][j] = solve(i+1,j+1);
    int op1 = solve(i + 1, j) + 1;
    int op2 = solve(i, j + 1) + 1;
    int op3 = solve(i + 1,j + 1) + 1;
    return memo[i][j] = min(min(op1,op2),op3);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        memset(memo, -1, sizeof memo);
        cin >> a >> b;
        cout << solve(0,0) << endl;
    }

    return 0;
}

