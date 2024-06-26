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
    long long cost[n+1];

    for(long long i=1;i<=n;i++)
    cin>>cost[i];
    
    long long m;
    cin>>m;

    vector<long long>adj[n+1];
    vector<long long>adj_rev[n+1];

    for(long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj_rev[y].push_back(x);
    }
    // debug("j");

    long long res=0;
    long long ways=1;
    const long long mod=(long long)(1e9)+7;
    vector<long long>topoSort;
    vector<long long>vis(n+1,0);
    // debug("h");
    function<void(long long)>f=[&](long long u)->void{

        vis[u]=1;
        // debug(u);
        for(long long v:adj[u])
        {
            if(!vis[v])
            {
                f(v);
            }
        }
        topoSort.push_back(u);
    };

    for(long long i=1;i<=n;i++)
    {
        if(!vis[i])
        f(i);
    }
    fill(all(vis),0);
    vector<long long>components;
    function<void(long long)>f1=[&](long long u)->void{
        components.push_back(u);
        vis[u]=1;
        for(long long v:adj_rev[u])
        {
            if(!vis[v])
            {
                f1(v);
            }
        }
    };
    reverse(all(topoSort));
    for(auto u:topoSort)
    {
        // debug(u);
        if(!vis[u])
        {
            components.clear();
            f1(u);
            vector<long long>c;
            for(long long v:components)
            {
                // debug(v,u);
                c.push_back(cost[v]);
            }
            sort(all(c));
            res+=c[0];
            // debug(c[0],u);
            long long count=1;
            for(long long i=1;i<(long long)c.size();i++)
            {
                if(c[i]==c[0])
                count++;
                else
                break;
            }
            ways=(ways%mod*count%mod)%mod;
        }
    }

    cout<<res<<" "<<ways<<endl;

}