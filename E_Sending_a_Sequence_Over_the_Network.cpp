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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++)
    cin>>b[i];
    vector<int>dp(n+1,-1);
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++)
    {
        if((i-b[i])>=0)
        {
            mp[i-b[i]].push_back(i);
        }
    }
    function<int(int)>f=[&](int i)->int{
        if(i>n)
        return 0;
        if(i==n)
        {
            return 1;
        }
        if(dp[i]!=-1)
        return dp[i];
       int res=f(i+b[i]+1);
       for(auto it:mp[i])
       {
          int x=f(it+1);
          res=res|x;
       }
       return dp[i]= res;
    };
    int x=f(0);
    // int x=0;
    if(x)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}