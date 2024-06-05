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
    long long n,m,k;
    cin>>n>>m>>k;

    vector<pair<long long,long long>>adj[n+1];
    multiset<vector<long long>>s1;
    for(long long i=1;i<=m;i++)
    {
        long long x,y,c;
        cin>>x>>y>>c;
        s1.insert({x,y,c});
        s1.insert({y,x,c});
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }
    long long cc=0;
    multiset<vector<long long>>s;
    for(long long i=1;i<=k;i++)
    {
        long long ss,c;
        cin>>ss>>c;
        if(s1.find({1,ss,c})!=s1.end())
        cc++;
        else
        s.insert({1,ss,c});
        adj[ss].push_back({1,c});
        adj[1].push_back({ss,c});
    }

    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>> >q;
    vector<long long>dist(n+1,(long long)(1e18));
    vector<long long>parent(n+1,-1);
    dist[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        auto it=q.top();
        q.pop();
        long long u=it.second;
        long long d=it.first;
        if(d!=dist[u])
        continue;
        for(auto v:adj[u])
        {
            if(dist[v.first]>(dist[u]+v.second))
            {
                parent[v.first]=u;
                dist[v.first]=dist[u]+v.second;
                q.push({dist[v.first],v.first});
            }
        }
    }
    multiset<vector<long long >>s3;
    long long sz1=(long long)(s.size());
    for(long long i=1;i<=n;i++)
    {
        // cout<<dist[i]<<" ";
        // debug(parent[i],i);
        if(s3.find({parent[i],i,dist[i]})==s3.end())
        {
            s.erase({parent[i],i,dist[i]});
            s3.insert({parent[i],i,dist[i]});
        }
    }
    // cout<<endl;
    long long sz2=(long long)(s.size());
    cout<<(sz2)+cc<<endl;
    // cout<<endl;    
}