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
    char c[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>c[i][j];
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(3,-1));
    function<int(int,int)>f=[&](int i,int j)->int{
      if(i<0 || j<0 || j>=3|| c[i][j]=='*')
      return 0;
       int a[]={-1,-1,-1};
       int b[]={0,-1,1};
       if(dp[i][j]!=-1)
       return dp[i][j];
       int res=0;
       for(int k=0;k<3;k++)
       {
          int x=i+a[k];
          int y=j+b[k];
          res=max(res,f(x,y));
       }
       int xx=0;
       if(c[i][j]=='c')
       xx++;
       xx+=res;
       return dp[i][j]= xx;
    };
    int x=f(n-1,0);
    int y=f(n-1,1);
    int z=f(n-1,2);
    int res=max({x,y,z});
    cout<<res<<endl;
}