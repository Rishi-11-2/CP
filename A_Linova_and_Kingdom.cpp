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
    long long n,k;
    cin>>n>>k;

    vector<long long>adj[n+1];
    priority_queue<pair<long long,long long>>pq;
    priority_queue<pair<long long,long long>>pq1;
    set<long long>vis;
    set<long long>x;
    function<void(long long,long long,long long)>f=[&](long long u,long long p,long long d)->void{
        long long flag=0;
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            flag=1;
            f(v,u,d+1);
        }
        if(!flag)
        {
            // debug(u);
            vis.insert(u);
            pq1.push({d,u});
        }
    };
    for(long long i=1;i<=n-1;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    f(1,0,0);
    while(k>0 && !pq1.empty())
    {
        auto it=pq1.top();
        pq1.pop();
        long long u=it.second;
        x.insert(u);
        k--;
        pq.push(it);
    }
    while(k>0 && !pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        long long u=it.second;
        long long d=it.first;
        // debug(u);
        if(x.find(u)==x.end())
        k--;
        x.insert(u);
        // debug(u,d);
        for(long long v:adj[u])
        {
            if(vis.find(v)==vis.end())
            {
                vis.insert(v);
                pq.push({d-1,v});
            }
        }
    }
    // for(auto it:x)
    // cout<<it<<" ";
    // cout<<endl;

    vis.clear();


    long long ans=0;
     function<void(long long,long long,long long)>f1=[&](long long u,long long p,long long d)->void{

        if(x.find(u)!=x.end())
        ans+=(d);
        long long new_d=d;
        if(x.find(u)==x.end())
        new_d++;
        // debug(u,d,new_d,ans);
        for(long long v:adj[u])
        {
            // debug(v);
            if(v==p)
            continue;
            f1(v,u,new_d);
        }
    };
    f1(1,0,0);
    cout<<ans<<endl;
    // f1(1,0,1,0);
}