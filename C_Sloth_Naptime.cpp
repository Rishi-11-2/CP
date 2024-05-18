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
        solve();
}
void solve()
{
    long long n;
    cin>>n;

    vector<long long>adj[n+1];

    for(long long i=1;i<n;i++)
    {
        long long u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<long long>levels(n+1,0);
    long long maxPower=log2(n)+10;

    vector<vector<long long>>parents(maxPower+1,vector<long long>(n+1,-1));

    function<void(long long,long long,long long)>dfs=[&](long long u,long long p,long long level)->void{

        levels[u]=level;

        parents[0][u]=p;
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            
            dfs(v,u,level+1);
        }
    };

    dfs(1,-1,0);

    for(long long i=1;i<maxPower;i++)
    {
        for(long long node=1;node<=n;node++)
        {
            long long inermediate=parents[i-1][node];

            if(inermediate!=-1)
            {
                parents[i][node]=parents[i-1][inermediate];
            }
        }
    }



    function<long long(long long,long long)>f=[&](long long node,long long k)->long long{

        for(long long i=0;i<maxPower;i++)
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


    function<long long(long long,long long)>lcaa=[&](long long a,long long b)->long long{

        if(levels[a]>levels[b])
        {
            a=f(a,levels[a]-levels[b]);
        }
        else if(levels[b]>levels[a])
        {
            b=f(b,levels[b]-levels[a]);
        }

        if(a==b)
        {
            return a;
        }

        for(long long i=maxPower-1;i>=0;i--)
        {
            if(parents[i][a]!=parents[i][b])
            {
                a=parents[i][a];
                b=parents[i][b];
            }
        }

        return parents[0][a];
    };


    long long q;
    cin>>q;

    for(long long i=1;i<=q;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long lca=lcaa(a,b);

        long long dist=levels[a]+levels[b] - 2*levels[lca];

        if(dist<=c)
        {
            cout<<b<<endl;
        }
        else
        {
            long long x=min(c,levels[a]-levels[lca]);

            long long node=a;

            node=f(node,x);

            c-=min(c,levels[a]-levels[lca]);

            if(c==0)
            {
                cout<<node<<endl;
            }
            else
            {
                node=f(b,levels[b]-(levels[lca]+c));
                cout<<node<<endl;
            }
        }
    }
}