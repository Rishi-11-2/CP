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
    long long t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
long long ans=(1LL<<61);
void dfs(long long curr,long long i,vector< vector<pair<long long,long long>>>&adj,vector<long long>&vis,long long n)
{
    if(i==n)
    {
        // debug(curr);
        ans=min(ans,curr);
        return ;
    }

    for(auto [v,w]:adj[i])
    {
        if(vis[v])
        continue;
        vis[v]=1;
        dfs(curr^w,v,adj,vis,n);
        vis[v]=0;
    }
}
void solve()
{

    long long n,m;
    cin>>n>>m;

    vector< vector<pair<long long,long long>>>adj(n+1);

    for(long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<long long>vis(n+1,0);
    vis[1]=1;
    dfs(0,1,adj,vis,n);

    cout<<ans<<endl;
    
}