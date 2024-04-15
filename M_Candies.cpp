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
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    const long long mod=(long long)(1e9+7);
    vector<vector<long long>>dp(n+1,vector<long long>(k+1,0));
    // vector<long long>prefix(n+1,0);
    // function<long long(long long,long long)>f=[&](long long i,long long k1)->long long{
    //     if(i==n)
    //     {
    //         if(k1==0)
    //         return 1;
    //         else
    //         return 0;
    //     }
    //     if(dp[i][k1]!=-1)
    //     return dp[i][k1];
    //     long long res=0;
    //     for(long long j=0;j<=a[i];j++)
    //     {
    //         res=(res%mod+f(i+1,k1-j)%mod)%mod;
    //     }
    //     return dp[i][k1]=res%mod;
    // };
    // cout<<f(0,k)<<endl;

    dp[n][0]=1;
    vector<long long>prev(k+1,0);
    vector<long long>curr(k+1,0);
    prev[0]=1;
    for(long long i=1;i<=k;i++)
    {
        prev[i]=(prev[i-1]%mod+dp[n][i]%mod)%mod;
    }
    for(long long i=n-1;i>=0;i--)
    {
        for(long long k1=0;k1<=k;k1++)
        {
            long long res=prev[k1];
            // cout<<prev[k1]<<" ";
            long long r1=k1;
            if(a[i]<=k1)
            r1=a[i];
            
            if((k1-r1)>=1)
            {
                res=(res%mod-prev[k1-r1-1]%mod+mod)%mod;
            }
            // for(long long j=0;j<=min(a[i],k1);j++)
            // {
            //     res=(res%mod+dp[i+1][k1-j]%mod)%mod;
            // }

            dp[i][k1]=res%mod;
            curr[k1]=dp[i][k1];
            if(k1>=1)
            {
                curr[k1]=(curr[k1]%mod+curr[k1-1]%mod)%mod;
            }
        }
        // cout<<endl;
        prev=curr;
    }
    cout<<dp[0][k]<<endl;
}