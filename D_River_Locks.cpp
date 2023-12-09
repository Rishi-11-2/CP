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
    long long n;
    cin>>n;
    long long arr[n];
    long long minm=0;
    long long s=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
        minm=max(minm,(s+i)/(i+1));
    }
    // cout<<minm<<endl;
    long long q;
    cin>>q;
    for(long long i=0;i<q;i++)
    {
        long long x;
        cin>>x;
        if(x<minm)
        cout<<-1<<endl;
        else
        {
            cout<<(s+x-1)/x<<endl;
        }
    }
}
