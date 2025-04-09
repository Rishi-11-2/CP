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
const long long mod=998244353;
long long binwpow(long long a,long long b)
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
const long long m=(long long)(5e5);
vector<long long>fact(m+1,0);
vector<long long>ifact(m+1,0);
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
    ifact[m]=binwpow(fact[m],mod-2);
    for(long long i=m-1;i>=0;i--)
    {
        ifact[i]=(ifact[i+1]%mod*(i+1)%mod)%mod;
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
    vector<long long>c(26,0);

    long long s=0;

    for(long long i=0;i<26;i++)
    {
        cin>>c[i];
        s+=c[i];
    }

    long long oddSum=(s+1)/2;

    vector<vector<long long>>dp(26,vector<long long>(s+1,-1));
    auto f=[&](long long i,long long sum,auto&& f)->long long{

        if(sum<0)
        {
            return 0;
        }
        if(sum==0)
        {
            return 1;
        }
        if(i==26)
        {
            return 0;
        }

        if(dp[i][sum]!=-1)
        return dp[i][sum];
      
        long long res=f(i+1,sum,f);

        if(c[i]>0)
        res=(res%mod+f(i+1,sum-c[i],f)%mod)%mod;

        return dp[i][sum]= res;
    };

    long long ans=f(0,oddSum,f);

    // debug(ans);

    ans=(ans%mod*fact[(s/2)]%mod)%mod;
    ans=(ans%mod*fact[(s+1)/2]%mod)%mod;

    for(long long i=0;i<26;i++)
    {
        if(c[i]==0)
        continue;

        ans=(ans%mod*ifact[c[i]]%mod)%mod;
    }

    cout<<ans<<endl;

}