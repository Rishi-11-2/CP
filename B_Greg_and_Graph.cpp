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
    long long n;
    cin>>n;

    long long grid[n+1][n+1];

    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            long long x;
            cin>>x;
            grid[i][j]=x;

        }
    }

    //  for(long long i=1;i<=n;i++)
    // {
    //     for(long long j=1;j<=n;j++)
    //     {
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<long long>order;
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        order.push_back(x);
    }
    reverse(all(order));
    vector<long long>removed(n+1,1);

    vector<vector<long long>>dp(n+1,vector<long long>(n+1,(long long)(1e10)));
    // for(long long i=1;i<=n;i++)
    // {
    //     dp[i][i]=0;
    // }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        dp[i][j]=min(dp[i][j],grid[i][j]);
    }
    vector<long long>res;
    for(auto x:order)
    {
        // debug(x);
        removed[x]=0;
        
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][x]+dp[x][j]);
            }
        }
        long long sum=0;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=n;j++)
            {
                 if(removed[i]==1 || removed[j]==1||i==j)
                continue;
                // debug(i,x,j);
                sum+=dp[i][j];
            }
        }

        res.push_back(sum);

    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    reverse(all(res));
    for(auto x:res)
    cout<<x<<" ";
    cout<<endl;
}