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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    queue< pair<int,pair<int,int>> >q;
    q.push({0,{1,-1}});
    vector<int>vis(n+1,0);
    int ans=(int)(1e9);
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int u=it.second.first;
        int p=it.second.second;
        int d=it.first;
        vis[u]=1;
        for(int v:adj[u])
        {
            if(vis[v] && v!=p && v==1)
            {
                ans=min(ans,d+1);
            }
            else if(!vis[v])
            {
                q.push({d+1,{v,u}});
                vis[v]=1;
            }
        }
    }
    if(ans==(int)(1e9))
    {
        ans=-1;
    }
    cout<<ans<<endl;
}