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
    int t;
    
        solve();
    
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<vector<int>>dp(n+1,vector<int>(11,-1));
    function<int(int,int,int)>f=[&](int i,int len,int prev)->int{
        if(i==n)
        {
            if(len==k+1)
            return 1;
            return 0;
        }
        if(len==k+1)
        return dp[i][len]= 1;
        if(dp[i][len]!=-1)
        return dp[i][len];
        int res=0;
        if(a[i]>prev)
        {
            res+=f(i+1,len+1,a[i]);
        }
        // res+=f(i+1,1,a[i]);
        res+=f(i+1,len,prev);
        return dp[i][len]=res;
    };

    int xx=f(0,0,0);
    cout<<xx<<endl;
}