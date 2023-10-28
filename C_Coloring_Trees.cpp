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
    long long n,m,k;
    cin>>n>>m>>k;
    vector<long long>colors(n);
    for(long long i=0;i<n;i++)
    {
        cin>>colors[i];
    }
    vector<vector<long long>>p(n,vector<long long>(m,0));
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            cin>>p[i][j];
        }
    }
    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(k+1,vector<long long>(m+1,-1)));
   long long flag=0;
    function<long long(long long,long long,long long)>f=[&](long long i,long long k1,long long prev)->long long{
        if(k1<0)
        return (long long)(1e18);
        if(i==n)
        {
            if(k1>0)
            return (long long)(1e18);
            flag=1;
            return 0;
        }
        if(dp[i][k1][prev]!=-1)
        return dp[i][k1][prev];
        if(colors[i]!=0)
        {
            if(i==0)
            return dp[i][k1][prev]= f(i+1,k1-1,colors[i]);
            else 
            {
                if(prev!=colors[i])
                return dp[i][k1][prev]= f(i+1,k1-1,colors[i]);
                else if(prev==colors[i])
                return dp[i][k1][prev]= f(i+1,k1,prev);
            }
        }
        long long res=(long long)(1e18);
        for(long long j=1;j<=m;j++)
        {
            if(prev==j)
            {
                res=min(res,p[i][j-1]+f(i+1,k1,prev));
            }
            else if(prev!=j)
            {
                res=min(res,p[i][j-1]+f(i+1,k1-1,j));
            }
        }
        return dp[i][k1][prev]= res;
    };
    long long x=f(0,k,0);
    if(flag)
    cout<<x<<endl;
    else
    cout<<-1<<endl;
}