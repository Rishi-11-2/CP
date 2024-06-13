
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
    vector<long long>parent;
    vector<long long>cost;

    DSU(long long n,long long *c)
    {
        parent.resize(n+1);
        cost.resize(n+1);
        for(long long i=0;i<=n;i++)
        {
            parent[i]=i;

            cost[i]=c[i];
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
        return ;

        if(cost[ulp_u]>cost[ulp_v])
        {
            cost[ulp_u]=cost[ulp_v];
            parent[ulp_u]=ulp_v;
        }
        else
        {
            cost[ulp_v]=cost[ulp_u];
            parent[ulp_v]=ulp_u;
        }
    }
};
void solve()
{
    long long n;
    cin>>n;

    vector<pair<long long,long long>>cities;
    cities.push_back({0,0});
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        cities.push_back({x,y});
    }

    long long c[n+1],k[n+1];
    c[0]=0;

    long long sum=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>c[i];
        sum+=c[i];
    }

    long long res=sum;
    for(long long i=1;i<=n;i++)
    cin>>k[i];

   
   DSU d(n,c);

   vector<pair<long long , pair<long long ,long long > >>edges;

   for(long long i=1;i<=n;i++)
   {
    for(long long j=i+1;j<=n;j++)
    {
         long long dist=abs(cities[i].first-cities[j].first)+abs(cities[i].second-cities[j].second);

         long long cost=(k[i]+k[j])*dist;


         edges.push_back({cost,{i,j}});
    }
   }

   sort(all(edges));
   
    vector<pair<long long,long long>>connections;
   for(auto it:edges)
   {
       if((int)(connections.size())==n-1)
       break;
       long long cost=it.first;
       long long u=it.second.first;
       long long  v=it.second.second;

       long long ulp_u=d.findUlp(u);
       long long ulp_v=d.findUlp(v);

       if(ulp_u==ulp_v)
       continue;
       
       long long maxC=max(d.cost[ulp_u],d.cost[ulp_v]);
    //    if(maxC<cost)
    //    break;

       if(maxC>cost)
       {
          sum-=maxC;
          sum+=cost;

         connections.push_back({u,v});
         d.unionBySize(u,v);
       }
   }

   cout<<sum<<endl;

   gp_hash_table<long long,long long>mp;

   for(long long i=1;i<=n;i++)
   {
    mp[d.findUlp(i)]++;
   }

   cout<<(long long)(mp.size())<<endl;

   for(auto it:mp)
   {
    cout<<it.first<<" ";
   }
   cout<<endl;


   cout<<(long long)(connections.size())<<endl;

   for(auto it:connections)
   {
    cout<<it.first<<" "<<it.second<<endl;
   }



    
}