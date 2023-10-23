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
    long long n,c;
    cin>>n>>c;
    long long a[n],b[n];
    for(long long i=0;i<n-1;i++)
    cin>>a[i];
    for(long long i=0;i<n-1;i++)
    cin>>b[i];
    vector<vector<long long>>dp(n,vector<long long>(2,0));
    dp[0][1]=c;
    for(long long i=1;i<n;i++)
    {
        dp[i][0]=min(dp[i-1][0]+a[i-1],dp[i-1][1]+a[i-1]);
        dp[i][1]=min(dp[i-1][0]+c+b[i-1],dp[i-1][1]+b[i-1]);
    }
    for(auto it:dp)
    {
        cout<<min(it[0],it[1])<<" ";
    }
    cout<<endl;
}