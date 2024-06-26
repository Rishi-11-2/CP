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
    long long n,m;
    cin>>n>>m;

    vector<long long>adj[n+1];
    vector<long long>adj_rev[n+1];
    for(long long i=1;i<=m;i++)
    {
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    vector<long long>vis(n+1,0);

    vector<long long>topoSort;

    function<void(long long)>f=[&](long long u)->void{
        vis[u]=1;

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
        {
            f(i);
        }
    }

    reverse(all(topoSort));
    fill(all(vis),0);
    vector<long long>components;
    function<void(long long)>f1=[&](long long u)->void{
        vis[u]=1;
        // debug(u);
        components.push_back(u);
        for(long long v:adj_rev[u])
        {
            if(!vis[v])
            {
                f1(v);
            }
        }
    };
    long long res=INT_MAX;
    for(auto node:topoSort)
    {
        if(vis[node])
        continue;

        components.clear();

        f1(node);

        long long sz=(long long)components.size();
        long long count1=(sz*(sz-1))/2;
        long long count2=((n-sz)*((n-sz)-1))/2;
        res=min(res,count1+count2);
        // debug(sz,count1,count2);
    }

    cout<<res<<endl;
}