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
    vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
    vector<int>prefix(n+1,0);
    function<long long(long long,long long)>f=[&](long long i,long long k1)->long long{
        if(i==n)
        {
            if(k1==0)
            return 1;
            else
            return 0;
        }
        if(dp[i][k1]!=-1)
        return dp[i][k1];
        long long res=0;
        for(long long j=0;j<=a[i];j++)
        {
            res=(res%mod+f(i+1,k1-j)%mod)%mod;
        }
        return dp[i][k1]=res%mod;
    };
    cout<<f(0,k)<<endl;
}