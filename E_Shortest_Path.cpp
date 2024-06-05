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
    long long n,m,k;
    cin>>n>>m>>k;

    vector<long long>adj[n+1];

    for(long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    set<vector<long long>>vx;
    for(long long i=1;i<=k;i++)
    {
        long long x,y,z;
        cin>>x>>y>>z;
        vector<long long>v1;
        v1.push_back(x);
        v1.push_back(y);
        v1.push_back(z);

        vx.insert(v1);
    }

   queue<pair<long long,pair<long long,long long>>>s;

    vector<vector<long long>>dis(n+1,vector<long long>(n+1,(long long)(1e18)));
    vector<vector<long long>>parent(n+1,vector<long long>(n+1,-1));
    dis[1][1]=0;
    s.push({0,{1,-1}});
    while(!s.empty())
    {
       auto it=s.front();
    //    s.erase(s.begin());
       s.pop();
       long long d=it.first;
       long long u=it.second.first;
       long long p_u=it.second.second;

    //    long long p_p_u=it[3];
        for(long long v:adj[u])
        {
            if(vx.find({p_u,u,v})==vx.end() && (dis[v][u])>(d+1))
            {
            //    debug(u,v);
               parent[v][u]=p_u;
               dis[v][u]=d+1;
               s.push({dis[v][u],{v,u}});
            }
        }
    }
    long long res=(long long)(1e18);
    for(long long i=1;i<=n;i++)
    {
        res=min(res,dis[n][i]);
    }
    if(res==(long long)(1e18))
    {
        cout<<-1<<endl;
        return;
    }

   cout<<res<<endl;

   vector<long long>path;
   long long node=n;
   long long nn=-1;
   for(long long i=1;i<=n;i++)
   {
    if(dis[n][i]==res)
    {
        nn=i;
    }
   }
   path.push_back(node);
   while(nn!=-1)
   {
       path.push_back(nn);
      long long g=parent[node][nn];
      node=nn;
      nn=g;

   }
   reverse(all(path));

   for(auto it:path)
   cout<<it<<" ";
   cout<<endl;

}