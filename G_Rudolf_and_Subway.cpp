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
vector<int>dist((int)(6e5),0);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;

    dist.clear();
    map<int,vector<int>>adj;
    // set<int>vis;
    for(int i=1;i<=m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;

        int new_c=c+(int)(3e5);
        dist[x]=(int)(1e9);
        dist[y]=(int)(1e9);
        dist[new_c]=(int)(1e9);
        adj[new_c].push_back(x);
        adj[new_c].push_back(y);

        adj[x].push_back(new_c);
        adj[y].push_back(new_c);
    }

    queue<pair<int,int>>q;

  

    int src,dest;
    cin>>src>>dest;

    dist[src]=0;
    q.push({0,src});

    while(!q.empty())
    {
        int u=q.front().second;
        int d=q.front().first;
        q.pop();
        // debug(u);
        if(d!=dist[u])
        continue;
        for(int v:adj[u])
        {
            if(dist[v]>d+1)
            {
                dist[v]=d+1;
                // vis[v]=1;
                // vis.insert(v);
                q.push({d+1,v});
            }
        }
    }

    cout<<(dist[dest]/2)<<endl;
}