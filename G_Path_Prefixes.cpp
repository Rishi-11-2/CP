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
  typedef tree< long long , null_type , less<long long> , rb_tree_tag, tree_order_statistics_node_update> pbdss;


vector<vector<long long>>adj[(int)(3e5)+10];
void f(long long u,long long p,long long sa,long long sb , pbdss &s,vector<long long>&res)
{
       long long x=s.order_of_key(sa);
        if(s.find(sa)!=s.end())
        x++;
        res[u]=x;
        for(auto v:adj[u])
        {
            if(v[0]==p)
            continue;
            s.insert(sb+v[2]);
            f(v[0],u,sa+v[1],sb+v[2],s,res);
            s.erase(sb+v[2]);
        }
}
void solve()
{
    long long n;
    cin>>n;


    pbdss s;
    for(long long i=0;i<=n;i++)
    {
        adj[i].clear();
    }
    for(long long i=2;i<=n;i++)
    {
        long long p,a,b;
        cin>>p>>a>>b;

        adj[p].push_back({i,a,b});
        adj[i].push_back({p,a,b});
    }
    vector<long long>res(n+1,0);
    for(auto v: adj[1])
    {
        s.insert(v[2]);
        f(v[0],1,v[1],v[2],s,res);
        s.erase(v[2]);
    }

    for(long long i=2;i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}