#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
class DSU{
public:
  vector<int>size;
  vector<int>parent;
  vector<set<string>>adj;
  
  DSU(int n,vector<vector<string>> &accounts)
  {
      size.resize(n+1,1);
      parent.resize(n+1,0);
      
      adj.resize(n+1);
      
      for(int i=0;i<n;i++)
      {
         int sz=(int)(accounts[i].size());
         for(int j=1;j<sz;j++)
        {
              auto it=accounts[i][j];
              adj[i].insert(it);
        }
      }
      for(int i=0;i<=n;i++)
      {
          size[i]=(int)(adj[i].size());
          parent[i]=i;
      }
  }
  
  
  int findUlp(int node){
      if(node==parent[node])
      return node;
      
      return parent[node]=findUlp(parent[node]);
  }
  void insert(int u,int v)
  {
      for(auto i:adj[v])
      {
          adj[u].insert(i);
      }
    //   adj[v].clear();
  }
  void unionBySize(int u,int v){
      
      int ulp_u=findUlp(u);
      int ulp_v=findUlp(v);
      
      if(size[ulp_u]>size[ulp_v])
      {
          size[ulp_u]+=size[ulp_v];
          parent[ulp_v]=ulp_u;
          insert(ulp_u,ulp_v);
      }
      else
      {
          size[ulp_v]+=size[ulp_u];
          parent[ulp_u]=ulp_v;
          insert(ulp_v,ulp_u);
      }
      
    }
};
void solve()
{
    int n;
    cin>>n;
    vector<vector<string>> accounts;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        vector<string>vx;
        for(int j=1;j<=x;j++)
        {
            string s;
            cin>>s;
            // debug
            vx.push_back(s);
        }
        accounts.push_back(vx);
    }
    // int n=accounts.size();
        DSU d(n+1,accounts);
        map<string,int>mp;
        map<int,string>name;
        set<string>vis;
        for(int i=0;i<n;i++)
        {
            name[i]=accounts[i][0];
            int sz=(int)(accounts[i].size());
            for(int j=1;j<sz;j++)
            {
                auto it=accounts[i][j];
                if(vis.find(it)!=vis.end())
                {
                    d.unionBySize(mp[it],i);
                    mp[it]=d.findUlp(mp[it]);
                }
                else
                {
                    vis.insert(it);
                    mp[it]=i;
                }
            }
        }
        
        set<int>x;
        
        for(int i=0;i<n;i++)
        {
            x.insert(d.findUlp(i));
        }
        vector<vector<string>>v;
        for(auto it:x)
        {
            vector<string>xx;
            xx.push_back(name[it]);
            for(auto i:d.adj[it])
            {
                xx.push_back(i);
            }
            v.push_back(xx);
        }
        sort(v.begin(),v.end());
        for(auto it:v)
        {
            for(auto i:it)
            cout<<i<<" ";
            cout<<endl;
        }
}