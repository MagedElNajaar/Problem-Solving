/**
 *    Author:  Maged M. AbdurRahman El-Najaar
 *    UVA: 11942 Lumberjack Sequencing
**/
#include<bits/stdc++.h>

using namespace std;

#define all(v)                ((v).begin()), ((v).end())
#define memo(v, d)            memset(v, d, sizeof(v))
#define lpV(i, v)       for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)
#define pb                    push_back
#define MP                    make_pair
#define bg                  begin()
#define en                  end()
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long         ll;
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;


const int N = 1e3 + 9, M = 2e4 + 9, OO = 0x3f3f3f3f;

int main() {
  int t;
  int first_number;
  cin>>t;
  int lum;
  cout<<"Lumberjacks:\n";
  while(t--) {
    cin>>first_number;
    bool check= false;
    bool check2= false;
    for (int i = 0; i < 9; i++) {
      cin >> lum;
      if (first_number < lum)
        check = true;
      else
        check2 = true;

      first_number = lum;
    }

    if (check&&check2)
      cout << "Unordered\n";
    else
      cout << "Ordered\n";

  }
  return 0;
}
