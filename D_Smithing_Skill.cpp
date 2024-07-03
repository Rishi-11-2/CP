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

    long long a[n];

    for(long long i=0;i<n;i++)
    cin>>a[i];

    long long b[n];

    for(long long i=0;i<n;i++)
    cin>>b[i];
    
    long long c[m];

    for(long long i=0;i<m;i++)
    cin>>c[i];
    

    vector<pair<long long,long long>>v;

    for(long long i=0;i<n;i++)
    {
        v.push_back({a[i]-b[i],a[i]});
    }

    sort(all(v));
    long long res=0;
    for(long long i=0;i<m;i++)
    {
        if(c[i]<v[0].second)
        continue;
        
        long long operations=(c[i]-v[0].second+v[0].first-1)/(v[0].first);
        long long cc=operations*2;

        res+=cc;

        c[i]-=operations*(v[0].first);

    }
    

    long long nn=(long long)(1e6)+1;

    vector<long long>dp(nn+1,0);
    vector<long long>minm(nn+1,(long long)(1e9));

    for(long long i=0;i<n;i++)
    {
        minm[a[i]]=min(minm[a[i]],a[i]-b[i]);
    }

    for(long long i=1;i<nn;i++)
    {
        minm[i]=min(minm[i],minm[i-1]);
    }

    for(long long i=1;i<nn;i++)
    {
        if(minm[i]==(long long)(1e9))
        continue;
        dp[i]=dp[i-minm[i]]+2LL;
    }

    for(long long i=0;i<m;i++)
    {
        res+=(dp[c[i]]);
    }
    cout<<res<<endl;
}