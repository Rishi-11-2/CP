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
struct node{
    long long u,pu,size_u,v,size_v,pv,n_cc;
    node(long long a,long long b,long long c,long long d,long long e,long long f,long long g)
    {
        u=a;
        pu=b;
        size_u=c;
        v=d;
        pv=e;
        size_v=f;
        n_cc=g;
    }
};
class DSU{

    public:
    vector<long long>size;
    vector<long long>parent;
    vector<node>history;
    long long cc;
    DSU(long long n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        cc=n;
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

        return findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);

        if(ulp_u==ulp_v)
        {
            node x(-1,-1,-1,-1,-1,-1,-1);
            history.push_back(x);
            return;
        }
        
        node x(ulp_u,ulp_u,size[ulp_u],ulp_v,ulp_v,size[ulp_v],cc);
        history.push_back(x);
        cc--;
        if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else{
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }

    void rollback(long long idx)
    {
        while((long long)history.size()>idx)
        {
            auto it=history.back();
            history.pop_back();
            if(it.u==-1)
            continue;
            long long u=it.u;
            long long pu=it.pu;
            long long size_u=it.size_u;
            long long v=it.v;
            long long pv=it.pv;
            long long size_v=it.size_v;

            cc=it.n_cc;
            size[u]=size_u;
            size[v]=size_v;
            parent[u]=pu;
            parent[v]=pv;
        }
    }


};
void solve()
{
    long long n,m;
    cin>>n>>m;

    DSU d(n);

    vector<long long>res;
    vector<long long>store;
    for(long long i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        if(s=="persist")
        {
            store.push_back((long long)d.history.size());
        }
        else if(s=="rollback")
        {
            d.rollback(store.back());
            store.pop_back();
            res.push_back(d.cc);
        }
        else
        {
            long long u,v;
            cin>>u>>v;
            d.unionBySize(u,v);
            res.push_back(d.cc);
        }
    }

    for(auto it:res)
    cout<<it<<endl;
}