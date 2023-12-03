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
     long long suff=0;
    for(long long i=0;i<n;i++)
    {
        suff+=arr[i];
    }
    long long c=1;
    long long s=0;
    for(long long i=0;i<n;i++)
    {
        s+=c*arr[i];
        suff-=arr[i];
        if(suff>0)
        {
            c++;
        }
    }

    cout<<s<<endl;
}