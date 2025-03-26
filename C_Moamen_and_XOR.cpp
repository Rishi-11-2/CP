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
const long long mod=(long long)(1e9)+7;
long long binpow(long long a,long long b)
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
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;

    const long long m =(long long)(2e5);

    fact.assign(m+1,0);
    ifact.assign(m+1,0);
    fact[0]=1;
    for(long long i=1;i<=m;i++)
    {
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
    }
    ifact[m]=binpow(fact[m],mod-2);
    for(long long i=m-1;i>=0;i--)
    {
        ifact[i]=(ifact[i+1]%mod*(i+1)%mod)%mod;
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
}

long long ncr(long long n,long long r)
{
    // debug(ifact[r]);
    long long a=fact[n]*(ifact[r]%mod*ifact[n-r]%mod)%mod;
    // debug(a);
    if(a>=mod)
    a-=mod;
    return a;
}

void solve()
{
    long long n,k;
    cin>>n>>k;
    long long sum=0;
    for(long long i=0;i<n;i+=2)
    {
        sum=sum+ncr(n,i);
        if(sum>=mod)
        sum-=mod;
    }

    vector<vector<long long>>dp(k+1,vector<long long>(3,-1));
    long long p=binpow(2,n);
    function<long long(long long,long long)>f=[&](long long i,long long flag)->long long{

        if(i<0)
        return 1;
        
        if(dp[i][flag]!=-1)
        return dp[i][flag];
        if(flag==0)
        {
            return dp[i][flag]=  (f(i-1,flag)%mod*p)%mod;
        }

        if(n%2)
        {
            return dp[i][flag]= (f(i-1,1)%mod*(sum+1)%mod)%mod;
        }
        return dp[i][flag]= ((f(i-1,1)%mod*(sum)%mod)%mod+f(i-1,0))%mod;
    };

    long long res=f(k-1,1);

    cout<<res<<endl;
}