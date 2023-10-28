#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
vector<vector<long long>>dp;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    long long m=(long long)(2e5);
    dp.assign(11,vector<long long>(m+1,0));
    const long long mod=(long long)(1e9)+7;
    /* dp[d][i]=dp[d+1][i-1]*/
    for(long long i=0;i<=9;i++)
    dp[i][0]=1;
    for(long long i=1;i<=(m);i++)
    {
    for(long long d=9;d>=0;d--)
    {
            long long res=0;
            if(d+1>9)
            {
                res=(dp[1][i-1]%mod+dp[0][i-1]%mod)%mod;
            }
            else
            {
                res=dp[d+1][i-1]%mod;
            }
            // cout<<d<<" "<<i<<" "<<res<<endl;
            dp[d][i]=res;
        }
    }
    // for(auto it:dp)
    // {
    //     for(auto i:it)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    // string s="0123456789";
    // long long res=0;
    // for(char c:s)
    // {
    //     long long x=(c-'0');
    //     res=(f(x,m));
    // }
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,m;
    cin>>n>>m;
    const long long mod=(long long)(1e9)+7;
    string s=to_string(n);
    long long res=0;
    for(char c:s)
    {
        long long x=(c-'0');
        res=(res%mod+(dp[x][m]))%mod;
    }
    cout<<res<<endl;
}