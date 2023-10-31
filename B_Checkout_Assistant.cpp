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
    vector<pair<long long,long long>>v;
    for(long long i=0;i<n;i++)
    {
        long long t,c;
        cin>>t>>c;
        v.push_back({t,c});

    }
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long t)->long long{
        if(t==0)
        return 0;
        if(i==n)
        {
            if(t>0)
            return (long long)(1e18);
        }
        if(dp[i][t]!=-1)
        return dp[i][t];
        long long res=f(i+1,t);
        res=min(res,f(i+1,max(0LL,t-(v[i].first+1)))+v[i].second);
        return  dp[i][t]= res;
    };
    cout<<f(0,n)<<endl;
}