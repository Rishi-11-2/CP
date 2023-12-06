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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    long long x=abs(arr[1]-arr[0]);
    for(long long i=2;i<n;i++)
    {
        long long y=abs(arr[i]-arr[i-1]);
        x=__gcd(x,y);
    }
    long long count=0;
    set<long long>s;
    for(long long i=0;i<n-1;i++)
    {
        count+=(arr[n-1]-arr[i])/x;
        s.insert(arr[i]);
    }
    long long xy=arr[n-1];
    s.insert(xy);
    while(s.find(xy)!=s.end())
    {
        xy-=x;
    }
    // cout<<xy<<endl;
    count+=(arr[n-1]-xy)/x;
    cout<<count<<endl;
}