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
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
   const long long mod=(long long)(998244353);
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long len)->long long{
        if(i==0)
        {
            // cout<<len<<endl;
            if(a[i]>0 && a[i]==len)
             return 1;
            else
             return 0;
        }
        if(dp[i][len]!=-1)
        return dp[i][len];
        long long res=0;
        long long x3=0;
        if(a[i]>0 && a[i]==len)
        {
            // cout<<i<<endl;
            x3=(1LL%mod+f(i-1,0)%mod)%mod;
        }
        long long x2=f(i-1,len+1)%mod;
        long long x1=f(i-1,len);
        res=(res%mod+x1%mod+x2%mod+x3%mod)%mod;
        return dp[i][len]=res%mod;
    };
    long long x=f(n-1,0LL);
    cout<<x<<endl;
}