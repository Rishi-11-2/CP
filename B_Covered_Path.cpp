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
    int v1,v2;
    cin>>v1>>v2;
    int t,d;
    cin>>t>>d;
    // cout<<v1<<" "<<v2<<endl;
    vector<vector<int>>dp(t+1,vector<int>(100000,-1));
    function<int(int,int)>f=[&](int i,int s)->int{
        // if(s<v1 || s>v2)
        // return -0x3f3f3f3f;
        if(s<1)
        return -(int)(1e9);
        if(i==t)
        {
            if(s==v2)
            return s;
            else
            return -(int)(1e9);
        }
        // cout<<i<<" "<<s<<endl;
        if(dp[i][s]!=-1)
        return dp[i][s];
        int res=f(i+1,s);
        for(int j=1;j<=d;j++)
        {
            res=max(res,f(i+1,s+j));
            res=max(res,f(i+1,s-j));
        }
        return dp[i][s]=(res+s);
    };
    cout<<f(1,v1)<<endl;
}