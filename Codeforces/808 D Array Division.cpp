#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

map <ll,int> pref,suff;
ll arr[(int)1e6+9];

int main(){
    ll sum = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        suff[arr[i]]++;
        sum += arr[i];
    }
    if(sum % 2 == 1){
        cout << "NO" << endl;
        return 0;
    }
    
    if(suff[sum/2]){
        cout << "YES" << endl;
        return 0;
    }
    
    ll prefix = 0, missing;
    
    for(int i=0;i<n;i++){
        prefix += arr[i];
        missing = sum / 2 - prefix;
        pref[arr[i]]++;
        suff[arr[i]]--;
        if(missing == 0 || (suff[missing] > 0 && missing > 0)){
            cout << "YES" << endl;
            return 0;
        }
    }
    ll suffix = 0;
    for(int i=n-1;i>=0;i--){
        suffix += arr[i];
        missing = sum / 2 - suffix;
        suff[arr[i]]++;
        pref[arr[i]]--;
        if((missing == 0 || (pref[missing] > 0 && missing > 0))){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
