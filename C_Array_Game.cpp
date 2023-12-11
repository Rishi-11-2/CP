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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int res=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        int x=abs(arr[i]-arr[i+1]);
        int minm=min(x+1,k);
        res=min(res,arr[i+1]-minm*arr[i]);
    }
    cout<<res<<endl;
}