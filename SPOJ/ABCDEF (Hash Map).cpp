#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

unordered_map<int,int>mp;
int n, arr[101],f;
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
                f = arr[a]*arr[b]+arr[c];
                mp[f]++;
            }}}
    long long ret = 0;
    for(int d=0;d<n;d++){
        for(int e=0;e<n;e++){
            for(int ff=0;ff<n;ff++)
            {       if(arr[d]==0)
                continue;
                else{
                    int temp = (arr[e] + arr[ff]) * arr[d];
                    if(mp.find(temp) != mp.end())
                        ret += mp[(temp)];
                }}}}
cout<<ret<<endl;
}
