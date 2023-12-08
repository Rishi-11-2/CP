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
const long long mod=(long long)(1e9)+7;
long long dp[22][(1<<21)+1];
long long f(long long i,long long mask,vector<vector<long long>>&a,long long n)
{
     if(i==n)
        {
            return 1;

        }
        if(dp[i][mask]!=-1)
        return dp[i][mask]%mod;
        long long res=0;
        for(long long j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                if((mask&(1<<j))==0)
                {
                    res=(res%mod+f(i+1,mask|(1<<j),a,n)%mod)%mod;
                }
            }
        }
    return dp[i][mask]= res%mod;
}
void solve()
{
    long long n;
    cin>>n;
    vector<vector<long long>>a(n+1,vector<long long>(n+1,0));
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        cin>>a[i][j];
    }
    memset(dp,-1,sizeof(dp));
    long long x=f(0,0,a,n);
    cout<<x<<endl;
}