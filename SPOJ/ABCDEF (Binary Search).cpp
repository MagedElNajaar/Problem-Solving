#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int n , arr[101] , f[1000001] , cnt;

int main() {

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    for(int a=0;a<n;a++)
        for(int b=0;b<n;b++)
            for(int c=0;c<n;c++)
                f[cnt++] = arr[a]*arr[b]+arr[c];
            sort(f,f+cnt);

            long long ret = 0;
            for(int d=0;d<n;d++){
                for(int e=0;e<n;e++){
                    for(int ff=0;ff<n;ff++)
                    {       if(arr[d]==0)
                        continue;
                        else{
                            int temp = (arr[e] + arr[ff]) * arr[d];
                            ret += upper_bound(f,f+cnt,temp) - lower_bound(f,f+cnt,temp);
                        }}}}

            cout << ret << endl;

            return 0;
}
