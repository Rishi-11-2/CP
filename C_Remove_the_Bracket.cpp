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
    long long n,s;
    cin>>n>>s;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    map<pair<long long,long long>,long long>mp;
    function<long long(long long,long long)>f=[&](long long i,long long z)->long long{
        if(i==n-1)
        {
            return z*a[i];
        }
        if(mp.find({i,z})!=mp.end())
        return mp[{i,z}];
        long long res=z*min(s,a[i]) + f(i+1,max(0LL,a[i]-s));
        res=min(res,z*max(0LL,a[i]-s)+f(i+1,min(s,a[i])));

        return mp[{i,z}]= res;
    };
    cout<< f(1,a[0])<<endl;
}