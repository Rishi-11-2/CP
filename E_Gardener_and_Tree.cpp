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
    long long n,k;
    cin>>n>>k;


    vector<long long>count(n+1,0);
    vector<long long>adj[n+1];
    for(long long i=1;i<=n-1;i++)
    {
        long long x,y;
        cin>>x>>y;
        count[x]++;
        count[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    queue<long long>q;
    vector<long long>dist(n+1,(long long)(1e9));
    for(long long i=1;i<=n;i++)
    {
        if(count[i]==1)
        {
            dist[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        long long u=q.front();
        q.pop();
        for(long long v:adj[u])
        {
            count[v]--;
            if(count[v]==1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    long long res=0;
    // for(long long i=1;i<=n;i++)
    // {
    //     if(dist[i]==INT_MAX)
    //     dist[i]=0;
    // }
    for(long long i=1;i<=n;i++)
    {
        if(dist[i]>k)
        {
            res++;
        }
    }
    cout<<res<<endl;
}