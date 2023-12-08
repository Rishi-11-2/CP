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
     long long maxm=(2*300*300);
     vector<vector<long long>>dp(300,vector<long long>(maxm+10,-1));
    function<long long(long long,long long)>f=[&](long long i,long long curr)->long long{
        if(i==n-1)
        {
            return 1;
        }
        if(dp[i][curr+maxm/2]!=-1)
        return dp[i][curr+maxm/2];
        long long res=0;
        if(curr==0)
        {
            res=(res%mod+f(i+1,a[i+1])%mod)%mod;
        }
        else
        {
            res=(res%mod+f(i+1,a[i+1]-curr));
            res=(res%mod+f(i+1,a[i+1]+curr));
        }
        return dp[i][curr+maxm/2]= res%mod;
    };
    long long x=f(1,a[1]);
    cout<<x<<endl;
}