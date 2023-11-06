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
    long long a[n],b[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    for(long long i=0;i<n;i++)
    cin>>b[i];
    const long long mod=998244353;
    vector<vector<long long>>dp(n+1,vector<long long>(3000+1,0));
    vector<vector<long long>>prev(n+1,vector<long long>(3000+1,0));
    dp[n][0]=1LL;
    prev[n][0]=1LL;
    /* Converting from recursive to iterative
    took almost 5 days . Had to think about how to optimise the code*/
    for(long long i=1;i<=3000;i++)
    {
        dp[n][i]=1LL;
        prev[n][i]=(prev[n][i-1]%mod+dp[n][i]%mod)%mod;
    }
    for(long long i=n-1;i>=0;i--)
    {
        dp[i][0]=prev[i+1][b[i]]%mod;
        if(a[i]>0)
        {
            dp[i][0]=(dp[i][0]-prev[i+1][a[i]-1]+mod)%mod;
        }
        for(long long j=1;j<=3000;j++)
        {
            dp[i][j]=prev[i+1][b[i]]%mod;
            long long x=j-1;
            if(a[i]>0)
            {
                x=max(j-1,a[i]-1)*1LL;
            }
            if(x>=0)
            dp[i][j]=((dp[i][j]%mod)-(prev[i+1][x]%mod)+mod)%mod;
        }
        prev[i][0]=dp[i][0];
        for(int j=1;j<=3000;j++)
        {
            prev[i][j]=(dp[i][j]%mod+prev[i][j-1]%mod)%mod;
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=4;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<dp[0][0]%mod<<endl;
    cout<<endl;
}