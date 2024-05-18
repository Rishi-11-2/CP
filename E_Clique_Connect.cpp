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


class DSU{
    public:
    vector<long long>size;
    vector<long long>parent;

    DSU(long long n)
    {
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(long long i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }

    }

    long long findUlp(long long node)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);

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
    long long n,m;
    cin>>n>>m;

    vector<vector<long long>>v;
    DSU d(n);
    for(long long i=1;i<=m;i++)
    {
        long long k,c;
        cin>>k>>c;
        vector<long long>vv;
        for(long long j=1;j<=k;j++)
        {
            long long x;
            cin>>x;
            vv.push_back(x);
        }
        for(long long j=0;j<k-1;j++)
        {
            v.push_back({c,vv[j],vv[j+1]});
        }
    }
    sort(all(v));
    // for(auto it:v)
    // {
    //     debug(it[0],it[1],it[2]);
    // }
    vector<long long>vis(n+1,0);
    long long res=0;
    for(auto it:v)
    {
        long long u=it[1];
        long long v=it[2];
        long long wt=it[0];
        if(d.findUlp(u)==d.findUlp(v))
        continue;
        vis[u]=1;
        vis[v]=1;
        // debug(u,v);
        res+=wt;
        d.unionBySize(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<res<<endl;
}