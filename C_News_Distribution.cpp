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
    long long n,m;
    cin>>n>>m;

    vector<long long>adj[n+1];

    for(long long i=1;i<=m;i++)
    {
        long long k;
        cin>>k;
        vector<long long>v;
        for(long long j=1;j<=k;j++)
        {
            long long x;
            cin>>x;
            v.push_back(x);
        }

        long long sz=(long long)(v.size());

        for(long long i=0;i<sz-1;i++)
        {
            adj[v[i]].push_back(v[i+1]);
            adj[v[i+1]].push_back(v[i]);
        }
    }

    vector<long long>nodes;

    vector<long long>vis(n+1,0);

    vector<long long>res(n+1,0);

    function<void(long long)>f=[&](long long u)->void{
        vis[u]=1;
        nodes.push_back(u);
        for(long long v:adj[u])
        {
            if(!vis[v])
            {
                f(v);
            }
        }
    };

    for(long long i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            f(i);

            long long sz=(long long)(nodes.size());
            for(long long i=sz-1;i>=0;i--)
            {
                res[nodes.back()]=sz;
                nodes.pop_back();
            }
        }
    }

    for(long long i=1;i<=n;i++)
    cout<<res[i]<<" ";
    cout<<endl;
}