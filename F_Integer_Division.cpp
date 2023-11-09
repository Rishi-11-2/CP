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
        solve();
}
void solve()
{
    long long n;
    cin>>n;
    string s;
    cin>>s;
    vector<long long>dp(n+1,0);
    vector<long long>pref(n+1,0);
    dp[0]=0;
    const long long mod= 998244353;
    pref[0]=1;
    for(long long i=1;i<=n;i++)
    {
        long long x=s[i-1]-'0';
        // cout<<x<<endl;
        dp[i]=((10LL%mod*dp[i-1]%mod)%mod+(pref[i-1]%mod*(x)%mod)%mod)%mod;
        pref[i]=(dp[i]%mod+pref[i-1]%mod)%mod;
    }
    cout<<dp[n]<<endl;
}