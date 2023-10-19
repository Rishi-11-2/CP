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
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<int>dp(n+1,0);
    for(int i=1;i<n;i++)
    {
        dp[i]=0x3f3f3f3f;
        for(int j=1;j<=k;j++)
        {
            if((i-j)>=0)
            {
                dp[i]=min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
            }
        }
        // cout<<dp[i]<<endl;
    }
    // for(auto it:dp)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    cout<<dp[n-1]<<endl;
}