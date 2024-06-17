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
class DSU{
    public:
    vector<long long>size;
    vector<long long>parent;

    DSU(long long n)
    {
        size.resize(n+2);
        parent.resize(n+2);

        for(long long i=0;i<=n+1;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    long long findUlp(long long node)
    {
        if(parent[node]==node)
        return node;
        
        return parent[node]= findUlp(parent[node]);
    }

  
};
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
    long long n,m;
    cin>>n>>m;

    DSU d(n+1);
    vector<long long>res;
    vector<long long>adj[n+1];
    vector<pair<long long,long long>>v;
    for(long long i=1;i<=m;i++)
    {
        long long q;
        cin>>q;
        if(q==1)
        {
            long long u,v;
            cin>>u>>v;

            d.parent[u]=v;
            adj[v].push_back(u);
        }
        else
        {
            long long u;
            cin>>u;
            v.push_back({u,d.findUlp(u)});
        }
    }
    set<long long>s;
    for(long long i=1;i<=n;i++)
    s.insert(d.findUlp(i));

    vector<long long>depth(n+1,0);
    vector<long long>vis(n+1,0);

    function<void(long long,long long)>f=[&](long long u,long long d)->void{

        vis[u]=1;
        depth[u]=d;
        for(long long v:adj[u])
        {
            if(!vis[v])
            f(v,d+1);
        }
    };

    for(auto node:s)
    {
        if(!vis[node])
        f(node,0);
    }

    for(auto it:v)
    {
        res.push_back(depth[it.first]-depth[it.second]);
    }

    for(auto it:res)
    cout<<it<<endl;
}