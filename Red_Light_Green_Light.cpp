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
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

void solve()
{
    int n,q;
    cin>>n>>q;

    vector<vector<int>>adj(n+2);

    vector<vector<int>>parents(32,vector<int>(n+1,-1));
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    vector<int>levels(n+1,0);
    vector<int>subtree(n+1,0);
    function<void(int,int,int)>f=[&](int u,int p,int level)->void{

        parents[0][u]=p;
        levels[u]=level;
        subtree[u]=1;

        for(int v:adj[u])
        {
            if(v!=p)
            {
                f(v,u,level+1);
                subtree[u]+=subtree[v];
            }
        }
    };

    f(1,-1,0);

    int maxPower=log2(n)+10;

     for(int i=1;i<maxPower;i++)
     {
        for(int j=1;j<=n;j++)
        {
            int x=parents[i-1][j];
            if(x!=-1)
            {
                parents[i][j]=parents[i-1][x];
            }
        }
     }

         function<int(int,int)>f1=[&](int node,int k)->int{
 
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
            a=f1(a,levels[a]-levels[b]);
        }
        else if(levels[b]>levels[a])
        {
            b=f1(b,levels[b]-levels[a]);
        }
 
        if(a==b)
        {
            return a;
        }
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


    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;

        int z=lca(x,y);
        int ans=0;
        int d=abs(levels[x]-levels[y]);
        if(z==x)
        {
            ans=(n-subtree[f1(y,d-1)])*subtree[y];
        }
        else if(z==y)
        {
            ans=(n-subtree[f1(x,d-1)])*subtree[x];

        }
        else
        {
            ans=subtree[x]*subtree[y];
        }
        cout<<ans<<"\n";
    }

}