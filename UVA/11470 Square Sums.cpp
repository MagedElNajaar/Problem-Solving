/**
 *    Author:  Maged M. AbdurRahman El-Najaar
 *    UVA : 11470 - Square Sums
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

int ar[10][10];

int main() {

  int n, t = 0;
  while (cin >> n && n) {

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> ar[i][j];
    cout << "Case " << ++t << ":";
    int d = n / 2;
    for (int k = 0; k < d; k++) {
      int sum = 0;
      for (int i = k; i < n - k; i++)
        sum += ar[k][i];
      for (int i = k; i < n - k; i++)
        sum += ar[n - k - 1][i];
      for (int i = k + 1; i < n - k - 1; i++)
        sum += ar[i][k];
      for (int i = k + 1; i < n - k - 1; i++)
        sum += ar[i][n - k - 1];

      cout << " " << sum;
    }
    if (n % 2) cout << " " << ar[n / 2][n / 2];
    cout << "\n";
  }
  return 0;
}
