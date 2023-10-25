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
    long long n,k,x;
    cin>>n>>k>>x;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
   vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(k+1,vector<long long>(x+1,-1)));
    function<long long(long long,long long,long long)>f=[&](long long i,long long k1,long long x)->long long{
        if(x<0)
        return -(long long)(1e18);
        if(i==n)
        {
            if(x==0)
            return 0;
           return -(long long)(1e18);
        }
        if(dp[i][k1][x]!=-1)
        return dp[i][k1][x];
        long long res=f(i+1,k,x-1)+a[i];
        if(k1>1)
        {
            res=max(res,f(i+1,k1-1,x));
        }
        return dp[i][k1][x]=res;
    };
 
    long long x1=f(0,k,x);
    if(x1<=0)
    cout<<-1<<endl;
    else
    {
        cout<<x1<<endl;
    }
}