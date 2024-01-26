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
vector<long long>fact;
vector<long long>ifact;
const long long mod=(long long)(1e9+7);
long long binpow(long long a,long long b)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res%mod*a%mod);
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}
long long modinverse(long long a,long long mod)
{
    return binpow(a,mod-2);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t;
    long long n=(long long)(1e3);
    fact.assign(n+1,0);
    ifact.assign(n+1,0);
    fact[0]=1;
    for(long long i=1;i<=n;i++)
    {
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
    }
    ifact[n]=modinverse(fact[n],mod);
    for(long long i=n-1;i>=0;i--)
    {
        ifact[i]=(ifact[i+1]%mod*(i+1)%mod)%mod;
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
}
long long nCr(long long n,long long r)
{
   long long res= (fact[n]%mod*(ifact[r]%mod*ifact[n-r]%mod)%mod)%mod;
   return res;
}
void solve()
{
    long long n,k;
    cin>>n>>k;
    long long arr[n];
    map<long long,long long>mp;
    set<long long,greater<long long>>s;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    vector<long long>v(all(s));
    long long i=k;
    long long res=1;
    long long j=0;
    // debug(nCr(1,1),fact[1],ifact[2]);
    while(i>0)
    {
        res=(res%mod*(nCr(mp[v[j]],min(i,mp[v[j]])))%mod)%mod;
        // debug(i,nCr(mp[v[j]],min(i,mp[v[j]])));
        i-=mp[v[j]];
        i=max(i,0LL);
        j++;
    }
    cout<<res<<endl;
}