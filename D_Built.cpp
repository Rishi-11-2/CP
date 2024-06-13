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
class DSU{

    public:
    vector<long long>size;
    vector<long long>parent;
    DSU(long long n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        for(long long i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }

    long long findUlp(long long node)
    {
        if(parent[node]==node)
        return node;

        return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);

        if(ulp_u==ulp_v)
        return;
        
        if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }
};
void solve()
{
    long long n;
    cin>>n;

    long long  cost=0;
    vector<pair<long long,long long>>vx;
    vector<pair<long long,long long>>vy;

    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;

        vx.push_back({x,i});
        vy.push_back({y,i});
    }

    sort(all(vx));
    sort(all(vy));

    vector<pair<long long,pair<long long,long long>>>edges;
    for(long long i=0;i<n-1;i++)
    {
        long long u=vx[i].second;
        long long v=vx[i+1].second;
        long long dist=vx[i+1].first-vx[i].first;
        edges.push_back({dist,{u,v}});
    }
    for(long long i=0;i<n-1;i++)
    {
        long long u=vy[i].second;
        long long v=vy[i+1].second;
        long long dist=vy[i+1].first-vy[i].first;
        edges.push_back({dist,{u,v}});
    }
    sort(all(edges));
    DSU d(n);
    
    long long m=(long long)(edges.size());
    for(long long i=0;i<m;i++)
    {

        long long w=edges[i].first;

        long long u=edges[i].second.first;

        long long v=edges[i].second.second;

        if(d.findUlp(u)==d.findUlp(v))
        continue;
        
        cost+=w;
        d.unionBySize(u,v);
       
    }

    cout<<cost<<endl;
}