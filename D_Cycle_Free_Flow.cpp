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
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>adj[n+1];
    map<pair<int,int>,int>mp;
    for(int i=1;i<=m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
        if(u>v)
        swap(u,v);
        
        mp[{u,v}]=wt;
    }


    int maxPower=log2(n)+10;
    vector<vector<int>>parents(maxPower,vector<int>(n+1,-1));
    vector<vector<int>>minm(maxPower,vector<int>(n+1,INT_MAX));

    vector<int>levels(n+1,0);

    function<void(int,int,int)>dfs=[&](int u,int p,int level)->void{

        levels[u]=level;
        parents[0][u]=p;
        int a=max(u,p);
        int b=min(u,p);
        if(p!=-1)
        {
            minm[0][u]=mp[{b,a}];
        }
        for(auto v:adj[u])
        {
            if(v.first==p)
            continue;
            dfs(v.first,u,level+1);
        }
    };

    dfs(1,-1,0);
    // for(int node=1;node<=n;node++)
    // cout<<minm[0][node]<<" ";
    for(int i=1;i<maxPower;i++)
    {
        for(int node=1;node<=n;node++)
        {
            int intermediate=parents[i-1][node];
            if(intermediate!=-1)
            {
                parents[i][node]=parents[i-1][intermediate];
                minm[i][node]=min(minm[i-1][intermediate],minm[i-1][node]);
            }
        }
    }   
    function<int(int,int)>fk=[&](int node,int k)->int{
        for(int i=0;i<maxPower;i++)
        {
            if(k&(1<<i))
            {
                node=parents[i][node];
                if(node==-1)
                return node;
            }
        }
        return node;

    };

    function<int(int,int)>lca=[&](int a,int b)->int{

        if(levels[a]>levels[b])
        {
            a=fk(a,levels[a]-levels[b]);
        }
        else if(levels[b]>levels[a])
        {
            b=fk(b,levels[b]-levels[a]);
        }
        if(a==b)
        return a;

        for(int i=maxPower-1;i>=0;i--)
        {
            if(parents[i][a]!=parents[i][b])
            {
                a=parents[i][a];
                b=parents[i][b];
            }
        }

        return parents[0][a];
    };


    function<int(int,int)>fkm=[&](int node,int k)->int{
        int res=INT_MAX;
        for(int i=0;i<maxPower;i++)
        {
            if(k&(1<<i))
            {
                res=min(res,minm[i][node]);
                node=parents[i][node];
            }
        }
        return res;
    };


    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        int c=lca(a,b);

        // debug(a,b,c);
        cout<<min(fkm(a,levels[a]-levels[c]),fkm(b,levels[b]-levels[c]))<<endl;
    }

}