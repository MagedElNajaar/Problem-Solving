/**
 *    Author:  Maged M. AbdurRahman El-Najaar
 *    Codefroces: 520 B. Two Buttons
 *    http://codeforces.com/contest/520/problem/B
**/
#include<bits/stdc++.h>

using namespace std;

#define all(v)          ((v).begin()), ((v).end())
#define sz(v)           ((int)((v).size()))
#define memo(v, d)      memset(v, d, sizeof(v))
#define lpV(i, v)       for(int i=0;i<sz(v);++i)
#define lp(n)           for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)
#define pb              push_back
#define MP              make_pair
#define bg              begin()
#define en              end()
#define sz              size()
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SORTarr(arr,n)  sort(arr,arr+n);
#define SORTv(V)        sort(V.begin(),V.end());

typedef long long         ll;
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

int n,m;
queue<int>Q;
int visited[20001];


/*

     (8)---(7)---(6)
    /
   /
(4)
   \
    \
     (3)---(6)
*/

int BFS()
{
    memset(visited,-1,sizeof visited); //Not Visited
    visited[n]=0; //start node
    Q.push(n);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u==m)
        {
            cout<<visited[u]<<endl;
            return 0;
        }

        int a=2*u;
        if(a<=20000 && visited[a]==-1)
        {
            visited[a]=visited[u]+1;
            Q.push(a);
        }
        int b=u-1;
        if(b>0 && visited[b]==-1)
        {
            visited[b]=visited[u]+1;
            Q.push(b);
        }
    }
}

int main()
{

    cin>>n>>m;

    BFS();

    return 0;

    
}
