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
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<vector<int>>dp(2002,vector<int>(2002,-1));
    function<int(int,int)>f=[&](int i,int j)->int{
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        int x1=(j+a[i])%h;
        int x2=(j+a[i]-1)%h;
        int r1=f(i+1,x1);
        int r2=f(i+1,x2);
        if(x1>=l && x1<=r)
        {
            r1++;
        }
         if(x2>=l && x2<=r)
        {
            r2++;
        }
        return  dp[i][j]=max(r1,r2);
    };
    cout<<f(0,0)<<endl;
}