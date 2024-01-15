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


class DSU{
public:
    vector<long long>parent;
    vector<long long>size;
    DSU(long long n)
    {
        parent.assign(n+1,0);
        size.assign(n+1,1);
        for(long long i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    long long findUlp(long long node)
    {
        if(node==parent[node])
        return node;

        return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);
        if(ulp_u==ulp_v)
        return ;

        if(size[ulp_u]<size[ulp_v])
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
    }

};
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
    long long n,m;
    cin>>n>>m;
    DSU d(n);

    vector<long long>score(n+1,0);
    vector<pair<long long,long long>>v;
    map<long long,long long>mp;
    for(long long i=1;i<=n;i++)
    {
        cin>>score[i];
        // v.push_back({score[i],i})
    }
    vector<long long>adj[n+1];

    for(long long i=1;i<=m;i++)
    {
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<long long>s;
    // for(int i=1;i<=n;i++)
    // s.insert(i);
    for(int i=1;i<=n;i++)
    {
        for(int u:adj[i])
        {
            if(score[i]==score[u])
            {
                d.unionBySize(i,u);
                // s.erase(u);
            }
        }

    }
    for(int i=1;i<=n;i++)
    {
        v.push_back({score[i],i});
    }
    sort(all(v));
    vector<long long>dist(n+1,1e18);
    dist[d.findUlp(1)]=1;
    // debug(dist[1]);
    for(long long i=1;i<(long long)(v.size());i++)
    {
        long long u=d.findUlp(v[i].second);
        // debug(u);
        for(long long v:adj[v[i].second]) /* although we find out the ultimate parent
        but still need to traverse the graph for that specific node*/
        {
            // debug(v);
            if(score[v]>score[u]) /* if score of v is greater than the score of u
             than it is impossible to reach u from v*/
            continue;
            if(dist[d.findUlp(v)]!=(long long)1e18)
            {
                if(dist[u]==(long long)1e18)
                dist[u]=dist[d.findUlp(v)]+1;
                else
                dist[u]=max(dist[d.findUlp(v)]+1,dist[u]);

               if(score[v]==score[u])
               dist[u]--;
            }
        }
    }
    // for(long long i=1;i<=n;i++)
    // {
    //     debug(dist[i]);
    // }
    long long x=dist[d.findUlp(n)];
    if(x==1e18)
    x=0;
    cout<<x<<endl;
}