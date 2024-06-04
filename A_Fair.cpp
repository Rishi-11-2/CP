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
    int n,m,k,s;
    cin>>n>>m>>k>>s;

    vector<int>arr(n+1);

    map<int,vector<int>>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];

        mp[arr[i]].push_back(i);
    }

    vector<int>adj[n+1];
    

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    map<int,vector<int>>mp1;
    for(int i=1;i<=k;i++)
    {
        queue<int>q;
        vector<int>dis(n+1,(int)(1e9));
        for(auto it:mp[i])
        {
            dis[it]=0;
            q.push(it);
        }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v:adj[u])
            {
                if(dis[v]>(dis[u]+1))
                {
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
           mp1[i].push_back(dis[i]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        int sum=0;
        sort(all(mp1[i]));
        for(int j=0;j<s;j++)
        {
            sum+=mp1[i][j];
            // debug(i,it);
        }
        cout<<sum<<" "; 
    }
    cout<<endl;
}