#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n,c;
vector <int> pos;

bool Vaild (int mid){
    int idx = pos[0], cows = 1;
    for(int i = 1; i < n;i++){
        if(pos[i] - idx >= mid){
            cows++;
            idx = pos[i];
        }
    }
    if(cows >= c) return 1;
    return 0;
}

int Binary_Search(int st,int ed){
    int ans;
    while (st <= ed){
        int mid = (st+ed) / 2; //mid == Space between cows
        if(Vaild(mid)){
            ans  = mid;
            st = mid + 1;
        }else ed = mid - 1;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        pos.clear();
        cin>>n>>c;
        int x;
        for(int i = 0;i<n;i++){
            cin>>x;
            pos.push_back(x);
        }
        sort(pos.begin(),pos.end());
        int st = 0, ed = pos[pos.size() - 1];
        cout << Binary_Search(st,ed) << endl;
    }

}
