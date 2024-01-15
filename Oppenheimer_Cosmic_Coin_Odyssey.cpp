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
vector<long long>dp;
vector<long long>fact;
vector<long long>ncr;
void solve();
long long inv(long long a,long long m) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a,m) % m;
}
const long long mod=(long long)(1e9+7);
long long  fexp(long long  a, long long  b){
    long long  ans = 1;
    for(long long i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= mod;
        ans %= mod;
    }
    return ans;
}

long long nCr(long long N, long long K){
    return fact[N] * fexp(fact[K] * fact[N-K] % mod, mod-2) % mod;
}
long long binpow(long long a,long long b,long long mod)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t;
    cin >> t;
    const long long m=(long long)(1e5);
    dp.assign(m+1,0);
    dp[0]=1;
    // Iterate till n
    long long mod=(long long)(1e9+7);
    for (long long i = 1; i <= m; i++) {
        // Calculate the ith Catalan number
        long long x=4*i-2;
        dp[i] = (dp[i-1]%mod * (4 * i - 2)%mod)%mod;
        dp[i]=(dp[i]%mod * inv(i + 1,mod)%mod)%mod;
        //    cout << res << " ";
    }
    fact.assign(m+1,0);
    fact[0]=1;
        for(long long i = 1; i <=m; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }

    while (t--)
    {
        solve();
    }
}
void solve()
{

    long long n;
    cin>>n;
    const long long mod=(long long)(1e9+7);
    long long x=binpow(2,n,mod);

    long long res=x;
    for(long long i=2;i<=n;i+=2)
    {
        long long z=nCr(n,i);
        z=(z%mod*(2%mod))%mod;
        long long y=(dp[i/2]%mod*(z)%mod)%mod;
        res=(res%mod+y%mod)%mod;
    }
    // debug(dp[2]);
    // if(n>1)
    // res=(res%mod+dp[n/2]%mod)%mod;
    cout<<res<<endl;
}