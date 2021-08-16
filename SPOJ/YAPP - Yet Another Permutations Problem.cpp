#include <iostream>
using namespace std;

int MOD = 1000000007;
//O(log(n))
long long fast_pow(int n){
    if(n == 0) return 1;
    long long ret = fast_pow(n/2);
    ret *= ret;
    if(n % 2) ret *= 2;

    return ret % MOD;
}
/*
int fast_pow(int n){
    long long ret = 1,x = 2;
    while(n > 0){
        if(n%2){
            ret = (ret * x) % MOD;
        }
        x = (x*x) % MOD;
        n/=2;
    }
    return ret;
}
*/

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin >> n;
        cout << fast_pow(n-1) << endl;
    }
    return 0;
}
