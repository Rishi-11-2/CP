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
long long inv(long long a,long long mod)
{
    long long x=binpow(a,mod-2,mod);
    return x;
}
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
    long long n;
    cin>>n;

    long long fact[5*n+1];
    fact[0]=1;
    const long long mod=(long long )(1e9+7);
    for(long long i=1;i<=3*n;i++)
    {
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
    }
    // debug(fact[2]);
    long long ifact[5*n+1];
    ifact[3*n]=inv(fact[3*n],mod);
    for(long long i=3*n-1;i>=0;i--)
    {
        ifact[i]=(ifact[i+1]%mod*(i+1)%mod)%mod;
    }

    long long x=(fact[n+n-1]%mod*(ifact[n]%mod*ifact[n-1]%mod)%mod)%mod;
    // debug(x);
    x=(2%mod*x%mod)%mod;
    cout<<x-n<<endl;
}