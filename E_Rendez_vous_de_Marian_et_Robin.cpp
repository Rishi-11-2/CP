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
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,m,h;
    cin>>n>>m>>h;

    set<long long>s;
    for(long long i=1;i<=h;i++)
    {
        long long x;
        cin>>x;
        s.insert(x);
    }
    
    vector<pair<long long,long long>>adj[n+1];
    for(long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue< pair<long long,pair<long long,long long>>, vector<pair<long long,pair<long long,long long>>>, greater<pair<long long,pair<long long,long long>>> >pq;
    long long horse=0;
    if(s.find(1)!=s.end())
    horse=1;
    pq.push({0,{1,horse}});

    vector<vector<long long>>dp1(n+1,vector<long long>(2,(long long)(1e18)));
    dp1[1][horse]=0;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        long long d=it.first;
        long long u=it.second.first;
        long long horse=it.second.second;
        if(d!=dp1[u][horse])
        continue;
        long long new_horse=horse;
        if(s.find(u)!=s.end())
        new_horse=1;
        for(auto v:adj[u])
        {
            long long cost=d+((new_horse)?(v.second/2):v.second);
            if(dp1[v.first][new_horse]>(cost))
            {
                dp1[v.first][new_horse]=cost;
                pq.push({dp1[v.first][new_horse],{v.first,new_horse}});
            }
        }
    }
    vector<vector<long long>>dp2(n+1,vector<long long>(2,(long long)(1e18)));
    horse=0;
    if(s.find(n)!=s.end())
    horse=1;
    dp2[n][horse]=0;
    pq.push({0,{n,horse}});

    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        long long d=it.first;
        long long u=it.second.first;
        long long horse=it.second.second;
        if(d!=dp2[u][horse])
        continue;
        long long new_horse=horse;
        if(s.find(u)!=s.end())
        new_horse=1;
        for(auto v:adj[u])
        {
            long long cost=d+((new_horse)?(v.second/2):v.second);
            if(dp2[v.first][new_horse]>(cost))
            {
                dp2[v.first][new_horse]=cost;
                
                pq.push({dp2[v.first][new_horse],{v.first,new_horse}});
            }
        }
    }
    // cout<<dp1[1][1]<<endl;
    long long res=(long long)(1e18);
    for(long long i=1;i<=n;i++)
    {
        long long x=min(dp1[i][0],dp1[i][1]);
        long long y=min(dp2[i][0],dp2[i][1]);
        // cout<<i<<" "<<x<<" "<<y<<endl;
        res=min(res,max(x,y));
    }
    if(res==(long long)(1e18))
    res=-1;
    cout<<res<<endl;
}