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
    vector<pair<long long,long long>>v;
    for(long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    map<long long,long long>mp;
    function<void(long long,long long)>f=[&](long long x,long long y)->void
    {
        if(y==0)
        return;
        if(y%2)
        { 
            mp[x]++;
            y--;
            f((2*1LL)*x,y/(2*1LL));
        }
        else
        {
            f((2*1LL)*x,y/(2*1LL));
        }
    };
    for(long long i=0;i<n;i++)
    {
        long long x=v[i].first;
        long long y=v[i].second;
        f(x,y);
    }
    long long count=0;
    for(auto it:mp)
    {
        // cout<<it.first<<" "<<it.second<<endl;
        if(it.second%2)
        {
            count+=min(it.second,2*1LL);
        }
        else
        count++;
    }
    cout<<count<<endl;
}