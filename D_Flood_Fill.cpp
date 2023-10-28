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
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(a.empty()|| a.back()!=x)
        {
            a.push_back(x);
        }
    }
    n=a.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    function<int(int,int)>f=[&](int i,int j)->int{
        if(i>=j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(a[i]==a[j])
        return dp[i][j]= 1+ f(i+1,j-1);
        return dp[i][j]= 1+min(f(i+1,j),f(i,j-1));
    };
    int x= f(0,n-1);
    cout<<x<<endl;
}