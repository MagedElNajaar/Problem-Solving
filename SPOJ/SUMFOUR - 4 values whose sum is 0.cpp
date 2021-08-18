#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int A[4000],B[4000],C[4000],D[4000],d,c,i,j;
    unordered_map<int ,int>m1;
    m1.reserve(16000000);
    for(i=0;i<n;i++)
    {   cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c=A[i]+B[j];
            m1[c]++;

        }
    }
    int ans=0;
    for( i=0;i<n;i++){
        for( j=0;j<n;j++){
            d=C[i]+D[j];
            if(m1.find(-d)!=m1.end()){
                ans+=m1[(-d)];
            }
        }
    }
    cout << ans << endl;
}
