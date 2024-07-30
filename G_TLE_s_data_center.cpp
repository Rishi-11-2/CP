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
    set<long long>adj[n+1];
    map<pair<long long,long long>,long long>mp;
    for(long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].insert(y);
        mp[{x,y}]=0;
        mp[{y,x}]=1;
        adj[y].insert(x);
    }
    vector<long long>dp(n+1,0);
    vector<long long>ans(n+1,0);
    function<void(long long,long long)>f=[&](long long u,long long p)->void{

        for(auto v:adj[u])
        {
            // debug(u,v);
            if(v==p)
            continue;
            f(v,u);
            dp[u]+=dp[v]+mp[{u,v}];
        }
        // debug(u,p,dp[u]);
    };


    f(1,-1);
    // for(long long i=1;i<=n;i++)
    // cout<<dp[i]<<" ";
    // cout<<endl;

    function<void(long long,long long)>f1=[&](long long u,long long p)->void{
        if(p!=-1)
        {
            dp[p]-=(dp[u]+mp[{p,u}]);
            dp[u]+=(1-mp[{p,u}])+dp[p];
        }
        ans[u]=dp[u];
        for(auto v:adj[u])
        {
            if(v==p)
            continue;
            f1(v,u);
        }
        if(p!=-1)
        {
            dp[u]-=(1-mp[{p,u}])+dp[p];
            dp[p]+=dp[u]+mp[{p,u}];
        }
    };
    f1(1,-1);
    long long minm=INT_MAX;
    for(long long i=1;i<=n;i++)
    {
        minm=min(minm,ans[i]);
    }
    vector<long long>v;
    for(long long i=1;i<=n;i++)
    {
        if(ans[i]==minm)
        {
            v.push_back(i);
        }
    }
    cout<<minm<<endl;
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    cout<<endl;


}