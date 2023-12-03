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
    long long b[n];
    for(long long i=0;i<n;i++)
    cin>>b[i];
    long long c[n];
    for(long long i=0;i<n;i++)
    cin>>c[i];
    
    vector<long long>cost(2001,(long long)(1e9));
    cost[1]=0;
    for(long long i=1;i<=1000;i++)
    {
        for(long long j=1;j<=i;j++)
        {
            long long x=i/j;
            cost[i+x]=min(cost[i+x],cost[i]+1);
        }
    }
    long long xxx=0;
    for(long long i=1;i<=1000;i++)
    {
        xxx=max(xxx,cost[i]);
    }
    long long s=(1000*1LL)*xxx;
    // cout<<s<<endl;
    vector<vector<long long>>dp(n+1,vector<long long>(s+1,-1));

    function<long long(long long ,long long )>f=[&](long long i,long long k1)->long long{

        if(i==n)
        return 0;
        if(dp[i][k1]!=-1)
        return dp[i][k1];
        long long res=f(i+1,k1);
        if(k1-cost[b[i]]>=0)
        res=max(res,c[i]+f(i+1,k1-cost[b[i]]));

        return dp[i][k1]=res;
    };

    long long x=f(0,min(s,k));
    cout<<x<<endl;
}