#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    
        solve();
    
}
void solve()
{
    long long n,m,y;
    cin>>n>>m>>y;

    long long grid[n][m];
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        cin>>grid[i][j];
    }

    queue<pair<long long,long long>>q;
    vector<vector<long long>>dp(n+1,vector<long long>(m+1,(long long)(1e18)));

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            if(i==0 ||j==0 || i==n-1||j==m-1)
            {
                dp[i][j]=grid[i][j];
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        long long i=it.first;
        long long j=it.second;
        long long a[]={1,-1,0,0};
        long long b[]={0,0,1,-1};
        for(long long k=0;k<4;k++)
        {
            long long x=a[k]+i;
            long long y=b[k]+j;
            if(x>=0 && y>=0 && x<n && y<m)
            {
                if(dp[x][y]>dp[i][j])
                {
                    if(grid[x][y]<=dp[i][j])
                    dp[x][y]=dp[i][j];
                    else
                    dp[x][y]=grid[x][y];
                    q.push({x,y});
                }
            }
        }
    }
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            // cout<<dp[i][j]<<" ";
            if(dp[i][j]==(long long)(1e18))
            dp[i][j]=grid[i][j];
        }
        // cout<<endl;
    }
    map<long long,long long>mp;
    for(long long i=1;i<=y;i++)
    {
        mp[i]=0;
    }
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            // cout<<dp[i][j]<<" ";
            mp[dp[i][j]]++;
        }
        // cout<<endl;
    }


    for(long long i=1;i<=y;i++)
    {
        mp[i]+=mp[i-1];
    }

    for(long long i=1;i<=y;i++)
    {
        cout<<(n*m)-mp[i]<<endl;
    }

}