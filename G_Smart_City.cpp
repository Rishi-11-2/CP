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
    long long n;
    cin>>n;
    vector<long long>adj[n+1];
    map<pair<long long,long long>,long long>mp;
    for(long long i=1;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        mp[{x,y}]=i;
        mp[{y,x}]=i;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long res=0;
    function<void(long long,long long,long long,long long)>f=[&](long long u,long long p,long long i,long long maxm)->void{
       res=max(res,i);

       for(long long v:adj[u])
       {
           if(p!=v)
           {
              if(p!=-1 && mp[{v,u}]<maxm)
              {
                f(v,u,i+1,mp[{v,u}]);
              }
              else
              {
                f(v,u,i,mp[{v,u}]);
              }
           }
       }
    };

    f(1,-1,1,0);
    cout<<res<<endl;
}