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
typedef tree< long long, null_type , less<long long> , rb_tree_tag, tree_order_statistics_node_update> pbdss;


vector<long long>adj[(long long)(1e5)+10];
long long res=0;

const long long mod=(long long)(1e9)+7;
void f( long long u,long long p,pbdss &s)
{
    
    long long sz=(long long)(s.size());
    long long x=s.order_of_key(u);
    res=(res%mod+x%mod)%mod;

    s.insert(u);
    for(long long v:adj[u])
    {
        if(v==p)
        continue;
        f(v,u,s);
    }

    s.erase(u);
    
}
void solve()
{
    long long n;
    cin>>n;

    long long a[n+1];
    long long b[n+1];
    res=0;
    for(long long i=0;i<=n;i++)
    {
        adj[i].clear();
    }
    for(long long i=1;i<n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<n;i++)
    {
        cin>>b[i];
    }
    for(long long i=1;i<n;i++)
    {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    pbdss s;

    f(1,0,s);

    cout<<res<<endl;

    
}