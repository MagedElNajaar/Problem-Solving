/**
 *    Author:  Maged M. AbdurRahman El-Najaar
 *    UVA : 11349 - Symmetric Matrix
**/
#include<bits/stdc++.h>
using namespace std;

#define all(v)                ((v).begin()), ((v).end())
#define sz(v)                ((int)((v).size()))
#define memo(v, d)            memset(v, d, sizeof(v))
#define lpV(i, v)        for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)
#define pb                    push_back
#define MP                    make_pair
#define bg                  begin()
#define en                  end()
#define sz size()
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long         ll;
typedef long double         ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

bool symmetric(long m[101][101],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {

            if(m[i][j]!=m[n-i-1][n-j-1])
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    int n;
    long m[101][101];
    char N,eq;
    int t;
    cin>>t;
    for(int test=1; test<=t; test++)
    {
        cin>>N>>eq>>n;

        bool ok=true;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>m[i][j];
                if(m[i][j]<0)
                {
                    ok=false;
                }
            }
        }
        if(ok&&symmetric(m,n))

            cout<<"Test #"<<test<<": Symmetric."<<endl;

        else
            cout<<"Test #"<<test<<": Non-symmetric."<<endl;
    }
    return 0;

}
