#include <bits/stdc++.h>
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
vector<vector<int>>adj;
set<int>s;
void dfs_cycle(int u, int p, int color[], int par[])
{ 
    if (color[u] == 2) {
        return;
    }
    if (color[u] == 1) {
        vector<int> v;
           
        int cur = p;
          s.insert(cur);
        while (cur != u) {
            cur = par[cur];
              s.insert(cur);
        }
        return;
    }
    par[u] = p;
    color[u] = 1;
    for (int v : adj[u]) {
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par);
    }
    color[u] = 2;
}
 
int dfs(int u,vector<int>&vis,int parent)
{
    // debug(u,parent);
    vis[u]=1;
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            if(dfs(v,vis,u))
            return 1;
        }
        else if(v!=parent)
        return 1;
    }
    return 0;
}
void solve()
{
    int n,a,b;
    s.clear();
    adj.clear();
    cin>>n>>a>>b;
    adj.resize(n+2);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>vis(n+1,0);
    int xx=dfs(1,vis,-1);
    if(xx==0||(a==b))
    {
        cout<<"NO"<<endl;
        return;
    }
    int color[n+2];
    int par[n+2];
    memset(color,0,sizeof(color));
    // memset(par,0,sizeof(par));
    dfs_cycle(1,0,color,par);
    // debug(0);

    if(s.find(b)!=s.end())
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}