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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;

    map<pair<int,int>,int>mp;

    vector<int>adj[n+1];

    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        mp[{a,b}]=c;
        mp[{b,a}]=c;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>levels(n+1,0);

    int maxPower=log2(n)+10;

    vector<vector<int>>parents(maxPower,vector<int>(n+1,-1));
    vector<vector<int>>dist(maxPower,vector<int>(n+1,0));


    function<void(int,int,int)>dfs=[&](int u,int p,int level)->void{

        levels[u]=level;

        parents[0][u]=p;

        if(p!=-1)
        {
            dist[0][u]=mp[{u,p}];
        }

        for(int v:adj[u])
        {
            if(v==p)
            continue;

            dfs(v,u,level+1);
        }
    };

    dfs(1,-1,0);


    for(int i=1;i<maxPower;i++)
    {
        for(int node=1;node<=n;node++)
        {
            int intermediate=parents[i-1][node];
            if(intermediate!=-1)
            {
                parents[i][node]=parents[i-1][intermediate];

                dist[i][node]=dist[i-1][node]+dist[i-1][intermediate];
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

    function<int(int,int)>kd=[&](int node,int k)->int{

        int d=0;
        for(int i=0;i<maxPower;i++)
        {
            if(k&(1<<i))
            {
                d+=dist[i][node];
                node=parents[i][node];
            }
        }
        // d+=dist[0][d];
        return d;
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

    vector<int>res;
    while(true)
    {
        string s;
        cin>>s;
        if(s=="DIST")
        {
            int a,b;
            cin>>a>>b;
            int c=lca(a,b);

            // debug(kd(a,levels[a]-levels[c]),kd(b,levels[b]-levels[c]));
            int d=kd(a,levels[a]-levels[c]) + kd(b,levels[b]-levels[c]);
            res.push_back(d);
        }
        else if(s=="KTH")
        {
            int a,b,k;
            cin>>a>>b>>k;

            int c=lca(a,b);

            int d1=levels[a]-levels[c]+1;
            if(k<=d1)
            {
                res.push_back(fk(a,k-1));
            }
            else
            {
                k-=d1;

                int d2=levels[b]-levels[c];
                d2-=k;

                res.push_back(fk(b,d2));
            }
        }
        else
        break;
    }


    for(auto it:res)
    cout<<it<<endl;

    cout<<endl;
}