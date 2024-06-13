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

    long long q[n+1];
    q[0]=0;
    int maxm=0;
    int idx=-1;
    for(long long i=1;i<=n;i++)
    {
        cin>>q[i];
        if(q[i]>maxm)
        {
            maxm=q[i];
            idx=i;
        }
    }
    
    long long m;
    // debug
   set<pair<long long,long long>>adj[n+1];

    cin>>m;

    for(long long i=1;i<=m;i++)
    {
        long long u,v,c;
        cin>>u>>v>>c;
        adj[u].insert({c,v});
    }

    set<pair<long long,long long>>s;

    s.insert({0,idx});

    vector<long long>dis(n+1,(long long)(1e18));
    long long res=0;
    while(!s.empty())
    {
        auto it=*s.begin();
        long long cost=it.first;
        long long u=it.second;
        dis[u]=cost;
        // res+=cost;
        s.erase(s.begin());
        
        for(auto v:adj[u])
        {
            if(dis[v.second]>(v.first))
            {
                s.erase({dis[v.second],v.second});
                dis[v.second]=v.first;
                s.insert({dis[v.second],v.second});
            }
        }
    }

    for(long long i=1;i<=n;i++)
    {
        if(dis[i]==(long long)(1e18))
        {
            cout<<-1<<endl;
            return;
        }
        res+=dis[i];
    }

    cout<<res<<endl;

    
    
}