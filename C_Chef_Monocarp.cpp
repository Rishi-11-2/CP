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
    long long n;
    cin>>n;
    long long t[n];
    for(long long i=0;i<n;i++)
    cin>>t[i];
/* we will have to sort as it is evident . WE can prove it greedily*/
/* time maximum that we can  have is 2*n. We can put any dish at time 2*n+1 between n+1 to 2*n using pigeonhole principle */
   sort(t,t+n);
   vector<vector<long long>>dp(n+1,vector<long long>(2*n+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long t1)->long long{
        if(i==n)
        return 0;
        if(t1>2*n)
        return (long long)(1e18);
        if(dp[i][t1]!=-1)
        return dp[i][t1];
        long long res=abs(t[i]-t1)+f(i+1,t1+1);
        res=min(res,f(i,t1+1));

        return dp[i][t1]= res;
    };
    long long res=f(0,1);
    cout<<res<<endl;
}