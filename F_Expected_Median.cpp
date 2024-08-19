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
long long m=(long long)(3e5);
const long long mod=(long long)(1e9)+7;
vector<long long>fact(m+1,0);
vector<long long>ifact(m+1,0);
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
        b>>=1LL;
    }
    return res;
}
long long inv(long long a,long long mod)
{
    return binpow(a,mod-2,mod);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    fact[0]=1;
    for(long long i=1;i<=m;i++)
    {
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
    }
    ifact[m]=inv(fact[m],mod);
    for(long long i=m-1;i>=0;i--)
    {
        ifact[i]=((i+1)%mod*ifact[i+1]%mod)%mod;
    }
    long long t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,k;
    cin>>n>>k;

    function<long long(long long,long long)>f=[&](long long n,long long r)->long long{
        long long res=fact[n];

        long long ans=(ifact[r]%mod*ifact[n-r]%mod)%mod;

        res=(res%mod*ans%mod)%mod;
        return res;
    };

    long long arr[n];
    long long count_one=0;
    long long count_zero=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        count_one+=arr[i];
        count_zero+=(1-arr[i]);
    }

    long long res=0;
        // debug(count_one,count_zero);
    for(long long i=0;i<=k;i++)
    {
        if(count_one<i || count_zero<(k-i))
        {
            continue;
        }
        // debug(f(count_one,i));
        long long a=0;
        long long  b=(f(count_one,i)%mod*f(count_zero,k-i)%mod)%mod;
        if(i>(k-i))
        {
            a=1;
        }
        res=(res%mod+(a*b)%mod)%mod;
    }

    cout<<res<<endl;

}