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
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
long long binpow(long long a,long long b,long long mod)
{
    long long res=1;
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

    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    const long long mod=(long long)(1e9)+7;
    long long denoInv=binpow((long long)(1e4),mod-2,mod);
    vector<long long>take(n+1);
    vector<long long>not_take(n+1);
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        take[i]=((x*denoInv)%mod);
        not_take[i]=((((long long)(1e4)-x)*denoInv)%mod);
    }

    // vector<vector<long long>>dp(n+1,vector<long long>(1024,0));
    vector<long long>dp(1024);
    dp[0]=1;
    for(long long i=n-1;i>=0;i--)
    {
        vector<long long>ndp(1024,0);
       for(long long xorr=0;xorr<=1023;xorr++)
       {
            long long res=((take[i]*dp[xorr^arr[i]])+(not_take[i]*dp[xorr]))%mod;
            ndp[xorr]=res;
       }
       dp=ndp;
    }
    long long res=0;
    for(long long i=1;i<=1023;i++)
    {
        res=(res+((dp[i]*i)*i))%mod;
    }
    cout<<res<<endl;
}