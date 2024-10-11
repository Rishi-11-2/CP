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
    long long n,m,p;
    cin>>n>>m>>p;

    long long s[p];

    vector<long long>val(n+1,0);
    for(long long i=0;i<p;i++)
    {
        cin>>s[i];
        val[s[i]]=1;
    }
    
    vector<pair<long long,long long>>adj[n+1];
    vector<long long>vis(n+1,0);
    for(long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<long long>global_dp(n+1,(long long)(1e18));
    vector<long long>v;
    for(long long i=1;i<=n;i++)
    {
        long long res=(long long)(1e18);
        long long vertex=-1;
        vector<long long>dp_temp(n+1,(long long)(1e18));
        for(long long j=1;j<=n;j++)
        {
            if(vis[j])
            continue;

           auto dp=global_dp;
           dp[j]=0;
           priority_queue< pair<long long,long long>, vector<pair<long long,long long>> , greater<pair<long long,long long>> >pq;
           pq.push({0,j});

           while(!pq.empty())
           {
             auto it=pq.top();
             pq.pop();
             long long d=it.first;
             long long u=it.second;
             if(d!=dp[u])
             {
                continue;
             }
             for(auto v:adj[u])
             {
                if(dp[v.first]>max(d,v.second))
                {
                    dp[v.first]=max(d,v.second);
                    pq.push({dp[v.first],v.first});
                }
             }
           }

           long long ans=0;
           for(long long k=1;k<=n;k++)
           {
             if(val[k])
             ans+=min(global_dp[k],dp[k]);
           }
        //    debug(ans,i,j);
           if(ans<res)
           {
              res=ans;
              vertex=j;
              dp_temp=dp;
           }
        }

        // debug(vertex,i);

        v.push_back(res);
        for(long long kk=1;kk<=n;kk++)
        {
            global_dp[kk]=min(global_dp[kk],dp_temp[kk]);
        }
        // if(vertex==-1)
        // continue;
        val[vertex]=0;
        vis[vertex]=1;
    }

    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}