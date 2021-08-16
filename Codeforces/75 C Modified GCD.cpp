#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;



vector <ll> Generate_Divisors(ll n = (ll)1e12){
    vector <ll> v;
    ll i = 1;
    for(; i * i < n;++i)
        if(n % i == 0)
            v.push_back(i), v.push_back(n / i);
        if(i * i == n)
            v.push_back(i);
        return v;
    
}

int main(){
    ll a,b;
    cin>>a>>b;
    ll G = __gcd(a, b);
    vector <ll> Divs = Generate_Divisors(G);
    sort(Divs.begin(),Divs.end());
    int q;
    cin>>q;
    while(q--){
        ll low,high;
        cin >> low >> high;
        auto it = upper_bound(Divs.begin(),Divs.end(),high);
        
        if(it == Divs.end() || *it > high)
            it--;
        
        if(low <= *it && *it <= high)
            cout << *it << endl;
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
