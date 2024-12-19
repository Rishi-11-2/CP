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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,q;
    cin>>n>>q;

    set<long long>adj[n+1];

    for(long long i=1;i<=n;i++)
    {
        if((i+1)<=n)
        {
            adj[i].insert(i+1);
            adj[i+1].insert(i);
        }
        else
        {
            adj[i].insert(i%n+1);
            adj[(i%n)+1].insert(i);
        }
    }

    vector<long long>vis(n+1,0);
    vis[1]=1;
    vis[2]=2;

    long long left=1;
    long long right=2;
    long long ans=0;
    for(long long i=1;i<=q;i++)
    {
        char ch;
        cin>>ch;

        long long idx;
        cin>>idx;

        vector<long long>dist(n+1,(long long)(1e9));
        priority_queue<pair<long long,long long>>pq;
        if(ch=='L')
        {
            pq.push({0,left});
            dist[left]=0;
        }
        else
        {
            pq.push({0,right});
            dist[right]=0;
        }

        while(!pq.empty())
        {
            auto it=pq.top();
            long long d=it.first;
            long long u=it.second;
            pq.pop();
            if(d!=dist[u])
            continue;
            for(long long v:adj[u])
            {
                if(dist[v]>(dist[u]+1) && vis[v]==0)
                {
                    dist[v]=dist[u]+1;
                    pq.push({dist[v],v});
                }
            }
        }
        // debug(idx,dist[idx]);

        ans+=dist[idx];
        if(ch=='L')
        {
            vis[left]=0;
            vis[idx]=1;
            left=idx;
        }
        else
        {
            vis[right]=0;
            vis[idx]=2;
            right=idx;
        }

    }
    cout<<ans<<endl;
}