#include <iostream>
using namespace std;
#define NEG -10000000

int main(){
    int ans = 0;
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    for(int i=0; i*a <=n;i++){
        for(int j=0;j*b<=n;j++){
            int x = i * a; //0
            int y = j * b; //3
            int k = (n-x-y) / c;
            if((n-x-y) % c != 0 || x + y > n)
                continue;
            int z = i + j + k;
            ans = max(ans,z);
        }
    }
    cout << ans << endl;
}


