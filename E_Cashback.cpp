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
    // cin >> t;
        solve();
}
void solve()
{
    long long n,c;
    cin>>n>>c;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    deque<long long>dq;
    vector<long long>dp(n+2,0);
    long long sum=0LL;
    dp[0]=0;
    for(long long i=1;i<=n;i++)
    {
        if(i>c)
        sum-=a[i-(c+1)];
        while(!dq.empty() && dq.front()<i-c)
        {
            dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()]>a[i-1])
        {
            dq.pop_back();
        }
        dq.push_back(i-1);
        sum+=a[i-1];
        dp[i]=dp[i-1]+a[i-1];
        if(i>=c && !dq.empty())
        {
            dp[i]=min(dp[i],dp[i-(c)]+sum-a[dq.front()]);
        }
    }
    cout<<dp[n]<<endl;
}