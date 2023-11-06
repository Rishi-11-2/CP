#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
        solve();
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    function<int(int,int)>f=[&](int i,int prev,int k1)->int{
        if(k1==k+1)
        return 1;
        if(i==n)
        return 0;
        
    };
}