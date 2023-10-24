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
    vector<vector<long long>>dp(k+1,vector<long long>(n+1,-1));
    const long long mod=(long long)(1e9+7);
    function<long long(long long,long long)>f=[&](long long i,long long prev)->long long{
        if(i==k)
        {
            return 1;
        }
        if(dp[i][prev]!=-1)
        return dp[i][prev];
        long long res=0;
        if(prev==0)
        {
            for(long long z=1;z<=n;z++)
            {
                res=((res%mod)+(f(i+1,z)%mod))%mod;
            }
        }
        else
        {
            long long x=prev;
            while(x<=n)
            {
                res=(res%mod)+(f(i+1,x)%mod);
                x=x+prev;
            }
        }
        return dp[i][prev]= res%mod;
    };
    cout<<f(0,0)<<endl;
}