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
    vector<long long>parity;
    bool flag;
    DSU(long long n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        parity.resize(n+1);
        flag=false;
        for(long long i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
            parity[i]=0;
        }
    }

    pair<long long,long long> findUlp(long long node)
    {
        if(node==parent[node])
        {
            return {node,0};
        }
        auto it=findUlp(parent[node]);

        parent[node]=it.first;
        parity[node]=(parity[node]+it.second)%2;
        return {parent[node],parity[node]};
    }

    void unionBySize(long long u,long long v)
    {
        auto ulp_u=findUlp(u);
        auto ulp_v=findUlp(v);

        if(ulp_u.first==ulp_v.first)
        {
            if(ulp_u.second==ulp_v.second)
            {
                flag=true;
                return ;
            }
        }

        if(size[ulp_u.first]>size[ulp_v.first])
        {
            size[ulp_u.first]+=size[ulp_v.first];
            parent[ulp_v.first]=ulp_u.first;
            parity[ulp_v.first]=(ulp_u.second+ulp_v.second+1)%2;
        }
        else
        {
            size[ulp_v.first]+=size[ulp_u.first];
            parent[ulp_u.first]=ulp_v.first;
            parity[ulp_u.first]=(ulp_u.second+ulp_v.second+1)%2;
        }
    }
};
void solve()
{
    long long n,m;
    cin>>n>>m;

    DSU d(n);
    vector<pair<long long,long long>>vv;
    for(long long i=1;i<=m;i++)
    {
        long long u,v;
        cin>>u>>v;
        vv.push_back({u,v});
    }
    for(long long i=0;i<m;i++)
    {
        long long u=vv[i].first;
        long long v=vv[i].second;
        d.unionBySize(u,v);
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<d.parity[i]<<" ";
        // }
        // cout<<endl;
        if(d.flag)
        {
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}