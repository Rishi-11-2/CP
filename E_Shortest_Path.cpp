#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    int n,m,k;
    cin>>n>>m>>k;

    vector<int>adj[n+1];

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    set<vector<int>>vx;
    for(int i=1;i<=k;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        vector<int>v1;
        v1.push_back(x);
        v1.push_back(y);
        v1.push_back(z);

        vx.insert(v1);
    }

   set<vector<int>>s;

    vector<vector<int>>dis(n+1,vector<int>(n+1,(int)(1e9)));
    dis[1][1]=0;
    s.insert({0,1,-1,-1});
    while(!s.empty())
    {
       auto it=*s.begin();
       s.erase(s.begin());

       int d=it[0];
       int u=it[1];
       int p_u=it[2];

       int p_p_u=it[3];
        for(int v:adj[u])
        {
            if(vx.find({p_u,u,v})==vx.end() && (dis[v][u])>(d+1))
            {
            //    debug(u,v);

               s.erase({dis[v][u],v,u,p_u});
               dis[v][u]=d+1;
               s.insert({dis[v][u],v,u,p_u});
            }
        }
    }
    int res=(int)(1e9);
    for(int i=1;i<=n;i++)
    {
        res=min(res,dis[n][i]);
    }
    if(res==(int)(1e9))
    {
        cout<<-1<<endl;
        return;
    }

   cout<<res<<endl;

   vector<int>path;
   int node=n;
   while(node!=-1)
   {
     path.push_back(node);
     int r=(int)(1e9);
     int next_node=-1;
     for(int i=1;i<=n;i++)
     {
        if(dis[node][i]<r)
        {
            r=dis[node][i];
            next_node=i;
        }
     }
     node=next_node;
   }
   reverse(all(path));

   for(auto it:path)
   cout<<it<<" ";
   cout<<endl;

}