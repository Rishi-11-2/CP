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
    const long long mod=998244353;
     /* curr -> i+1, nright-> i+2*/
     vector<vector<long long>>dp(300,vector<long long>(620,-1));
    function<long long(long long,long long,long long)>f=[&](long long i,long long curr,long long nright)->long long{
        if(i==n-3)
        {
            return 1;
        }
        if(dp[i][nright+300]!=-1)
        return dp[i][nright+300];
        long long x1=f(i+1,nright-a[i+1],a[i+3])%mod;
        long long x2=f(i+1,nright+a[i+1],a[i+3])%mod;
        long long res=(x1%mod+x2%mod)%mod;
        return dp[i][nright+300]= res%mod;
    };
    long long x=f(0,a[1],a[2]);
    // if(n>3)
    // {
    //     x-=1;
    // }
    cout<<x<<endl;
}