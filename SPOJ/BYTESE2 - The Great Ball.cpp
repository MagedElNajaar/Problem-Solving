#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
vector <pair <int,int> > v;

int main(){
    int t,people;
    cin>>t;
    int enter,leave;
    while(t--){
        v.clear();
        cin>>people;
        for(int i=0;i<people;i++){
            cin >> enter >> leave;
            v.push_back({enter,0});
            v.push_back({leave,1});
        }
        sort(v.begin(),v.end());
        int cnt = 0,ans = 0;
        for(int i =0;i<v.size();i++){
            v[i].second == 0 ? cnt++ : cnt--;
            ans = max(cnt,ans);
        }
        cout << ans << endl;
    }
    return 0;
}
