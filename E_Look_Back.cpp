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
    
    long long prev=arr[0];
    long long count=0LL;
    for(long long i=1;i<n;i++)
    {
        long long x=arr[i]*1LL;
        while(x<prev)
        {
            x=(x*(2*1LL));
            count++;
        }
        prev=x;
    }
    cout<<count<<endl;
}