#include <iostream>
using namespace std;

int main() {
    long long t[(int)1e5 + 9];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    sort(t,t+n);
    long long wait = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(wait <= t[i]){
            ans++;
            wait+=t[i];
        }
    }
    cout << ans << endl;
    return 0;
}
