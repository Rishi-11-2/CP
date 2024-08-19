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

    long long arr[n+1];

    for(long long i=1;i<=n;i++)
    cin>>arr[i];
    
    vector<long long>adj[n+1];
    for(long long i=2;i<=n;i++)
    {
        long long x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    long long res=0;
    vector<long long>ans(n+1,0);
    function<void(long long,long long)>f=[&](long long u,long long p)->void{
        long long sum=0;
        long long minm=INT_MAX;
        long long flag=0;
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            f(v,u);
            flag=1;
            minm=min(minm,ans[v]);
            sum+=arr[v];
        }
        if(!flag)
        {
            ans[u]=1;
            return;
        }
        ans[u]=minm+1;
        if(arr[u]>sum)
        {
            res+=(arr[u]-sum)*minm;
        }
    };
    f(1,-1);
    cout<<res<<endl;
}