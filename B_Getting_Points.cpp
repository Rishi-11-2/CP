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
    long long n,p,l,t;
    cin>>n>>p>>l>>t;

    long long low=1;
    long long high=n;
    long long res=n;

    function<long long(long long)>f=[&](long long mid)->long long{

        long long nT=(n/7LL);
        if(n%7)
        nT++;
        long long ans=mid*l+min(nT,mid*2LL)*t;
        if(ans>=p)
        return 1LL;
        return 0LL;
    };
    while(low<=high)
    {
        long long mid=(low+high)/2LL;
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    // cout<<res<<endl;
    cout<<n-res<<endl;
}