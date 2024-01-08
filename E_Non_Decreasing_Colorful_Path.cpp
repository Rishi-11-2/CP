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
    long long n,m;
    cin>>n>>m;
    long long a[n+1];
    for(long long i=1;i<=n;i++)
    cin>>a[i];
    
    vector<long long>adj[n+1];
    for(long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long flag=0;
    function<long long(long long,long long)>f=[&](long long u,long long p)->long long{
        long long res=0;
        // long long flag=0;
        // long long cflag=0;
        // debug(u,p);
        if(u==n)
        {
            flag=1;
            return 1;
        }
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            if(a[v]>a[u])
            {
                // flag=1;
                res=max(res,f(v,u));
            }
            // cflag=1;
        }
        // if(!flag)
        // return 0;
        res=res+1;
        return res;
    };

    long long x=f(1,0);
    if(!flag)
    {
        cout<<0<<endl;
        return;
    }
    cout<<x<<endl;
}