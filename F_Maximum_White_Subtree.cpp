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

    long long arr[n+1];

    for(long long i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==0)
        arr[i]=-1;
    }

    vector<long long>adj[n+1];

    for(long long i=1;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<long long>dp(n+1,0);


    function<void(long long,long long)>dfs=[&](long long u,long long p)->void{

        long long res=0;
        for(long long v:adj[u])
        {
            if(v!=p)
            {
                dfs(v,u);
                res=max(res,res+dp[v]);
            }
        }
        dp[u]=arr[u]+res;
    };

    dfs(1,-1);

    // for(long long i=1;i<=n;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;

    //rerooting
    vector<long long>ans(n+1,0);
    function<void(long long,long long)>dfs2=[&](long long u,long long p)->void{
        if(p!=-1)
        {
            dp[p]-=max(dp[u],0LL);
            dp[u]+=max(dp[p],0LL);
        }
        ans[u]=dp[u];
        for(long long v:adj[u])
        {
            if(v!=p)
            {
                dfs2(v,u);
            }
        }
        if(p!=-1)
        {
            dp[u]-=max(0LL,dp[p]);
            dp[p]+=max(dp[u],0LL);
        }
    };

    dfs2(1,-1);

    for(long long i=1;i<=n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    
}