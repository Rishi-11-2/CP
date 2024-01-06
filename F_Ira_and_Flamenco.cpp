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
long long binpow(long long a,long long b,long long mod)
{
    long long res=1LL;
    while(b>0)
    {
        if(b&1LL)
        {
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1LL;
    }
    return res;
}
void solve()
{
    long long n,m;
    cin>>n>>m;
    long long a[n];
    set<long long>s;
    map<long long,long long>mp;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        s.insert(a[i]);
    }
    vector<long long>v(all(s));
    s.erase(all(s));
    long long product=1;
    long long res=0;
    long long sz=(long long)(v.size());
    if(sz<m)
    {
        cout<<0<<endl;
        return;
    }
    // for(auto it:v)
    // cout<<it<<" ";
    // cout<<endl;

    const long long mod=(long long)(1e9+7);
    for(long long i=0;i<m;i++)
    {
        product=(product%mod*mp[v[i]]%mod)%mod;
        s.insert(v[i]);
    }
    // debug(product);
    long long minm=*s.begin();
    long long maxm=*s.rbegin();
    if((maxm-minm)<m)
    {
        res=(res%mod+product%mod)%mod;
    }
    for(long long i=m;i<sz;i++)
    {

        s.erase(v[i-m]);
        s.insert(v[i]);
        long long x=binpow(mp[v[i-m]],mod-2,mod);
        product=(product%mod*x%mod)%mod;
        product=(product%mod*mp[v[i]]%mod)%mod;
        minm=*s.begin();
        maxm=*s.rbegin();
        // debug(minm,maxm);
        if((maxm-minm)<m)
        {
            res=(res%mod+product%mod)%mod;
        }
    }


    cout<<res<<endl;

}