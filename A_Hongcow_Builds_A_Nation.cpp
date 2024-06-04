#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    long long n,m,k;
    cin>>n>>m>>k;

    set<long long>v;
    for(long long i=1;i<=k;i++)
    {
        long long x;
        cin>>x;
        v.insert(x);
    }
    // sort(all(v));
    vector<long long>adj[n+1];
    for(long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<long long>components;
    vector<long long>vis(n+1,0);

    function<void(long long)>f=[&](long long u)->void{

        components.push_back(u);
        vis[u]=1;
        for(long long v:adj[u])
        {
            if(!vis[v])
            {
                f(v);
            }
        }
    };

    long long maxm=0;
    long long res=0;
    for(auto i:v)
    {
        f(i);
        long long sz=(long long)(components.size());
        long long sum=0;
        for(long long v:components)
        {
            sum+=(long long)(adj[v].size());
        }
        sum=sum/2;
        maxm=max(maxm,sz);
        long long y=(sz*(sz-1))/2;
        // debug(i,sum,y);
        res+=(y-sum);
        components.clear();
    }

    long long sum=0;
    long long count=0;
    for(long long i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            sum+=(long long)(adj[i].size());
            count++;
        }
    }
    sum=sum/2;
    long long x=(count*(count-1))/2;
    x-=sum;
    res+=x;
    res+=(count*maxm);
    cout<<res<<endl;
}