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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    vector<pair<long long,long long>>adj[n+1];
    map<pair<long long,long long>,long long>mp;
    for(long long i=1;i<n;i++)
    {
        long long u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
        mp[{u,v}]=wt;
        mp[{v,u}]=wt;
    }
    vector<long long>dp(n+1,0);
    vector<long long>subtree(n+1,0);
    function<void(long long,long long)>dfs=[&](long long u,long long p)->void{
        subtree[u]=1;
        for(auto v:adj[u])
        {
            if(v.first==p)
            continue;
            dfs(v.first,u);

            dp[u]+=(dp[v.first]+v.second*subtree[v.first]);
            subtree[u]+=subtree[v.first];
        }
    };

    dfs(1,-1);
    vector<long long>ans(n+1,0);
    function<void(long long,long long)>dfs1=[&](long long u,long long p)->void{
        if(p!=-1)
        {
            dp[p]-=(dp[u]+mp[{u,p}]*subtree[u]);
            subtree[p]-=subtree[u];
            dp[u]+=(dp[p]+mp[{u,p}]*subtree[p]);
            subtree[u]+=subtree[p];
        }

        ans[u]=dp[u];
        // debug(u,dp[u]);
        for(auto v:adj[u])
        {
            if(v.first==p)
            continue;
            dfs1(v.first,u);
        }

        if(p!=-1)
        {
            subtree[u]-=subtree[p];
            dp[u]-=(dp[p]+mp[{u,p}]*subtree[p]);
            subtree[p]+=subtree[u];
            dp[p]+=(dp[u]+mp[{u,p}]*subtree[u]);
        }

    };

    dfs1(1,-1);

    long long res=(long long)(1e18);

    for(long long i=1;i<=n;i++)
    {
        res=min(res,ans[i]);
    }

    cout<<res<<endl;
}