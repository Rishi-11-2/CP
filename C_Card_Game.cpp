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
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    long long sum=0;
    long long res=0;
    for(long long i=n-1;i>=0;i--)
    {
        if(i%2==0)
        {
            res=max(res,sum+a[i]);
        }
        else
        {
            res=max(res,sum);
        }
        if(a[i]>0)
        sum+=a[i];
    }
    cout<<res<<endl;
}