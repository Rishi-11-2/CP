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
    int n;
    cin>>n;

    vector<int>adj[n+1];

    vector<vector<int>>vv;
    map<vector<int>,int>mp;
    for(int i=2;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;

        vector<int>x;
        x.push_back(u);
        x.push_back(v);
        sort(all(x));
        vv.push_back(x);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int>levels(n+1,0);

    int maxPower=log2(n)+10;

    vector<vector<int>>parents(maxPower+1,vector<int>(n+1,-1));

    function<void(int,int,int)>dfs=[&](int u,int p,int level)->void{

        parents[0][u]=p;

        levels[u]=level;

        for(int v:adj[u])
        {
            if(v==p)
            continue;
            
            dfs(v,u,level+1);
        }
    };


    dfs(1,-1,0);

    for(int i=1;i<=maxPower;i++)
    {
        for(int node=1;node<=n;node++)
        {
            int intermediate=parents[i-1][node];
            if(intermediate!=-1)
            {
                parents[i][node]=parents[i-1][intermediate];
            }
        }
    }
    function<int(int,int)>f=[&](int node,int k)->int{

        for(int i=0;i<=maxPower;i++)
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
            a=f(a,levels[a]-levels[b]);
        }
        else if(levels[b]>levels[a])
        {
            b=f(b,levels[b]-levels[a]);
        }

        if(a==b)
        return a;

        for(int i=maxPower;i>=0;i--)
        {
            if(parents[i][a]!=parents[i][b])
            {
                a=parents[i][a];
                b=parents[i][b];
            }
        }

        return parents[0][a];
    };

    vector<int>values(n+1,0);

    int q;
    cin>>q;

    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;

        int c=lca(a,b);
        // debug(a,b,c);
        values[a]++;
        values[b]++;
        values[c]-=2;
    }


    function<int(int,int)>dfs2=[&](int u,int p)->int{

        for(int v:adj[u])
        {
            if(v==p)
            continue;

            int y=dfs2(v,u);

            vector<int>x;
            x.push_back(u);
            x.push_back(v);

            // debug(y,v,u);
            sort(all(x));
            mp[x]=y;

            values[u]+=y;
        }

        return values[u];
    };

    int yy=dfs2(1,-1);


    for(auto it:vv)
    {
        cout<<mp[it]<<" ";
    }
    cout<<endl;

}