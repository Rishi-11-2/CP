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
    vector<long long>experience;
    vector<vector<long long>>adj;
    DSU(long long n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        adj.resize(n+1);
        experience.resize(n+1);
        for(long long i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
            experience[i]=0;
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
        if(ulp_u==ulp_v)
        return; 

        
       if(size[ulp_u]>size[ulp_v])
       {


         vector<long long>v;

         for(auto node:adj[ulp_v])
         {
            experience[node]+=experience[ulp_v];

            experience[node]-=experience[ulp_u];

            adj[ulp_u].push_back(node);
         }
         experience[ulp_v]-=experience[ulp_u];
         adj[ulp_u].push_back(ulp_v);

         parent[ulp_v]=ulp_u;
         size[ulp_u]+=size[ulp_v];
       }
       else
       { 
            vector<long long>v;

         for(auto node:adj[ulp_u])
         {
            experience[node]+=experience[ulp_u];

            experience[node]-=experience[ulp_v];

            adj[ulp_v].push_back(node);
         }
         experience[ulp_u]-=experience[ulp_v];
         adj[ulp_v].push_back(ulp_u);

           
          parent[ulp_u]=ulp_v;
          size[ulp_v]+=size[ulp_u];
       }
    }
};
void solve()
{
    long long n,m;
    cin>>n>>m;
    DSU d(n+1);
    vector<long long>res;
    for(long long i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        if(s=="add")
        {
            long long u,v;
            cin>>u>>v;

            d.experience[d.findUlp(u)]+=v;


        }
        else if(s=="join")
        {
            long long u,v;
            cin>>u>>v;
            d.unionBySize(u,v);
        }
        else
        {
            long long u;
            cin>>u;
            if(u==d.findUlp(u))
            res.push_back(d.experience[u]);
            else
            res.push_back(d.experience[u]+d.experience[d.findUlp(u)]);
        }
    }

    for(auto it:res)
    cout<<it<<endl;
}