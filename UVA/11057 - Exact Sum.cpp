#include <bits/stdc++.h>
using namespace std;

int n , m , arr[10000];

bool binary_search(int val, int s,int e)
{
    while(s <= e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == val) return 1;
        if(arr[mid] < val) s = mid + 1;
        if(arr[mid] > val) e = mid - 1;
    }
    return 0;
}

int main() {

    int f, s;

    while(cin >> n)
    {
        for(int i=0;i<n;i++)
            cin >> arr[i];
        cin >> m;

        sort(arr,arr+n);
        for(int i=0;i<n;i++)
            if(binary_search(m-arr[i], i+1 , n-1))
            {
                f = arr[i];
                s = m-arr[i];
            }
        cout << "Peter should buy books whose prices are " << f <<" and " << s << "." << endl << endl;
    }

    return 0;
}
