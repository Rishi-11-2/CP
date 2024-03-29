#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC tar("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast")
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
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);
        solve();
}
const long long mod1=(long long)(1e9+7);
const long long mod2=(long long)(1e9+1);
const long long mod3=(long long)(1e15+5);
const long long p1=uniform_int_distribution<long long>(0,mod1-1)(rng);
const long long p2=uniform_int_distribution<long long>(0,mod2-1)(rng);
const long long p3=uniform_int_distribution<long long>(0,mod3-1)(rng);
struct Hash{

    long long *pref1;
    // vector<long long>hash;
    long long *base_pow1;
    long long *base_pow2;
    long long *pref2;
    string s;
    long long n;
    Hash(const string &a)
    {
        s=a;
        n=s.length();
        pref1=(long long*)(malloc((n+1)*sizeof(long long)));
        pref2=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow1=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow2=(long long*)(malloc((n+1)*sizeof(long long)));
        base_pow1[0]=1;
        base_pow2[0]=1;
        pref1[0]=1;
        pref2[0]=1;
        for(long long i=1;i<=n;i++)
        {
            base_pow1[i]=(p1*base_pow1[i-1])%mod1;
            base_pow2[i]=(p2*base_pow2[i-1])%mod2;
            pref1[i]=((pref1[i-1]*p1)%mod1+s[i-1]+997)%mod1;
            pref2[i]=((pref2[i-1]*p2)%mod2+s[i-1]+997)%mod2;
        }
    }

    long long get_hash(long long l,long long r)
    {
        long long h1=pref1[r+1]-(pref1[l]*base_pow1[r-l+1])%mod1;
        long long h2=pref2[r+1]-(pref2[l]*base_pow2[r-l+1])%mod2;
        if(h1<0)
        h1+=mod1;
        
        if(h2<0)
        h2+=mod2;
        long long h3=(h1*p1)%mod3;
        h3=(h3+h2)%mod3;
        return h3;
    }

};
void solve()
{
    string s;
    cin>>s;
    long long n=s.length();
    vector<long long>v(26,0);
    string x;
    cin>>x;
    long long m=x.length();
    for(long long i=0;i<m;i++)
    {
        long long  val=(x[i]-'0');
        v[i]=(1-val);
    }
    Hash h(s);
    long long k;
    cin>>k;
    vector<long long>prefix(n,0);
    prefix[0]=v[s[0]-'a'];
    for(long long i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+v[s[i]-'a'];
    }
    // for(auto it:prefix)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    long long count=0;
    gp_hash_table<long long,long long>st;
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<=i;j++)
        {
            long long val=prefix[i];
            if(j>0)
            {
                val-=prefix[j-1];
            }
            if(val<=k)
            {
                auto vvv=h.get_hash(j,i);
                // debug(j,i,vvv);
                st[vvv]=1;
            }
        }
    }
    count=(long long)(st.size());
    cout<<count<<'\n';
}