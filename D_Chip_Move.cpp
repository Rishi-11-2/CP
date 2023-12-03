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
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    const int mod=(int)(998244353);
    function<int(int ,int)>f=[&](int i,int k1)->int{
        if(i<0)
        return 0;
        if(i==0)
        {
            if(k1<k)
            return 1;
            return 0;
        }
        if(k1<k)
        return 0;
        if(dp[i][k1]!=-1)
        return dp[i][k1];
        int y=k1;
        int c=1;
        int res=0;
        while(y<=i)
        {
            res=(res%mod+f(i-y,k1-1)%mod)%mod;
            c++;
            y=c*k1;
        }

        return dp[i][k1]=res%mod;
    };
    vector<int>res;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=k;j<=i;j++)
        {
            ans=(ans%mod+f(i,j)%mod)%mod;
        }
        res.push_back(ans%mod);
    }

    for(auto it:res)
    cout<<it<<" ";
    cout<<endl;
}