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
    vector<pair<long long,long long>>v;
    for(long long i=0;i<n;i++)
    {
        long long l,r;
        cin>>l>>r;
        v.push_back({l,r});
    }
    function<long long(long long)>f=[&](long long mid)->long long{
        long long l=0;
        long long r=0;
        for(long long i=0;i<n;i++)
        {
            l=l-mid;
            r=r+mid;
            l=max(l,v[i].first);
            r=min(r,v[i].second);
            if(l>r)
            return 0;
        }
        return 1;
    };
    long long low=0;
    long long high=(long long)(1e9);
    long long res=high;
    while(low<=high)
    {
        long long mid=(low+high)/2;

        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    cout<<res<<endl;
}