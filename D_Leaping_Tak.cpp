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
    long long n,k;
    cin>>n>>k;
    set<long long>s;
    vector<pair<long long,long long>>v;
    for(long long i=1;i<=k;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    const long long mod=998244353;
    vector<long long>dp(3*n+1,0);
    dp[n]=1;
    vector<long long>suffix(3*n+1,0);
    suffix[n]=1;
    for(long long i=n-1;i>=1;i--)
    {
        for(long long j=0;j<k;j++)
        {
            long long l=v[j].first;
            long long r=v[j].second;
            // cout<<l<<" "<<r<<" "<<i<<endl;
            dp[i]=(dp[i]%mod+suffix[l+i]%mod-suffix[i+r+1]%mod+mod)%mod;

        }
        suffix[i]=(dp[i]%mod+suffix[i+1]%mod)%mod;
    }
    cout<<dp[1]<<endl;
}