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
    long long n,k;
    cin>>n>>k;
    const long long mod=(long long)(1e9)+7;
    vector<vector<vector<long long>>>dp(n+10,vector<vector<long long>>(k+10,vector<long long>(2,0)));
    // function<long long(long long,long long,long long)>f=[&](long long i,long long k1,long long dir)->long long{
    //     if(i<1||i>n||k1<1)
    //     return 1;
       
    //     long long res=(x1%mod+x2%mod)%mod;
    //     return dp[i][k1][dir]= res%mod;
    // };
    // // cout<<f(1,k,0)<<endl;
      for(int k1=0;k1<=k;k1++)
      {
        dp[0][k1][0]=1;
        dp[0][k1][1]=1;
        dp[n][k1][0]=1;
        dp[n][k1][1]=1;
      }
      for(int i=0;i<=n;i++)
      {
        dp[i][0][1]=1;
        dp[i][0][0]=1;
      }
        for(int k1=k;k1>=1;k1--)
        {
          for(int i=1;i<=n;i++)
          {
            for(int dir=0;dir<=1;dir++)
            {
                long long x1=0;
                long long x2=0;
                if(dir==0)
                {
                    x1=dp[i+1][k1][dir]%mod;
                    if(k1>1)
                    {
                        x2=dp[i-1][k1-1][1-dir]%mod;
                    }
                }
                else if(dir==1)
                {
                    x1=dp[i-1][k1][dir]%mod;
                    if(k1>1)
                    {
                        x2=dp[i+1][k1-1][1-dir]%mod;
                    }
                }
                long long res=(x1%mod+x2%mod)%mod;
                dp[i][k1][dir]= res%mod;
            }
        }
    }
    cout<<dp[1][k][0]<<endl;
}