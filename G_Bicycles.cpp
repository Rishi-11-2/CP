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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,m;
    cin>>n>>m;
    vector<pair<long long,long long>>adj[n+1];
    for(long long i=1;i<=m;i++)
    {
        long long x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});

    }
    long long s[n+1];
    for(long long i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    priority_queue<tuple<long long,long long,long long>,vector<tuple<long long,long long,long long>> , greater<tuple<long long,long long,long long>> >pq;
    pq.push(make_tuple(0,s[1],1));
    set<pair<int,int>>st;
    while(!pq.empty())
    {
        long long dist,ss,u;
        tie(dist,ss,u)=pq.top();
        pq.pop();
        // debug(dist,ss,u);

        if(u==n)
        {
            cout<<dist<<endl;
            return;
        }
        if(st.find({u,ss})!=st.end())
        continue;
         
         st.insert({u,ss});
        for(auto it:adj[u])
        {
            long long v=it.first;
            long long w=it.second;
            long long newDist=dist+w*ss;
            long long sss=min(ss,s[v]);  
            auto  t=make_tuple(newDist,sss,v);
            pq.push(t);
        }
    }
}