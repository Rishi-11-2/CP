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

bool cmp(pair<long long,long long>a,pair<long long,long long>b)
{
    if(a.first==b.first)
    return a.second<b.second;

   return a.first>b.first;
}
void solve()
{
    long long n,k;
    cin>>n>>k;

    vector<long long>adj[n+1];
    for(long long i=1;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<long long>levels(n+1,0);
    vector<long long>size(n+1,0);

    function<void(long long ,long long,long long)>f=[&](long long u,long long p,long long level)->void{

        size[u]=1;
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            
            f(v,u,level+1);
            size[u]+=size[v];
        }
        levels[u]=(level-size[u]);
    };

    f(1,-1,0);

    vector<pair<long long,long long>>v;
    for(long long i=1;i<=n;i++)
    {
        v.push_back({levels[i],i});
    }

    sort(all(v),cmp);
    // for(auto it:v)
    // debug(it.first,it.second);
    vector<long long>vis(n+1,0);

    for(long long i=0;i<k;i++)
    {
        // debug(v[i].second);
        vis[v[i].second]=1;
    }

    long long res=0;
    function<void(long long,long long,long long)>f1=[&](long long u,long long p,long long level)->void{

        long long newLevel=level+1;
        if(vis[u]==1)
        {
            newLevel--;
            res+=level;
        }
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            
            f1(v,u,newLevel);
        }
    };

    f1(1,-1,0);

    cout<<res<<endl;
}