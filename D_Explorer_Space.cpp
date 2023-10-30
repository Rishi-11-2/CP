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
    long long n,m,k;
    cin>>n>>m>>k;
    vector<vector<long long>>a(n+1,vector<long long>(m+1,0));
    vector<vector<long long>>b(n+1,vector<long long>(m+1,0));
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m-1;j++)
        {
            
            long long z;
            cin>>z;
            a[i][j]=z;
        }
    }
    for(long long i=0;i<n-1;i++)
    {
        for(long long j=0;j<m;j++)
        {
            long long z;
            cin>>z;
            b[i][j]=z;
        }
    }
    long long flag=0;
    // long long xx=n;
    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(k+1,-1)));
    function<long long(long long,long long,long long)>f=[&](long long i,long long j,long long k)->long long{
        if(k==0)
        {
                return 0;
        }
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        long long res=(long long)(1e18);
       if(i+1<n)
       {
          res=min(res,f(i+1,j,k-1)+b[i][j]);
       }
       if(i-1>=0)
       {
          res=min(res,f(i-1,j,k-1)+b[i-1][j]);
       }
       if(j+1<m)
       {
          res=min(res,f(i,j+1,k-1)+a[i][j]);
       }
       if(j-1>=0)
       {
          res=min(res,f(i,j-1,k-1)+a[i][j-1]);
       }
        return dp[i][j][k]= res;
    };

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            if(k%2)
            {
                cout<<-1<<" ";
                continue;
            }
            long long x=f(i,j,k/(2LL));
            // if(flag==1)
            cout<<(2LL*x)<<" ";
            // else
            // cout<<-1<<" ";
        }
        cout<<endl;
    }
}