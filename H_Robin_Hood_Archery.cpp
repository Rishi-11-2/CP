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
class Xor_Hash{
    public:
    vector<long long>arr;
    vector<long long>hash1;
    vector<long long>hash2;
    const long long k1=(long long)(1e7)+1;
    const long long k2=(long long)(1e4)+3;
    const long long mod1=999999929;
    const long long mod2=999999937;
    const long long h1=37;
    const long long h2=41;
    long long n;
    Xor_Hash(vector<long long>&v)
    {
        arr=v;
        n=(long long)v.size();
        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        build();
    }
    void build()
    {
        for(long long i=1;i<=n;i++)
        {
            hash1[i]=binpow(arr[i-1]+k1,h1,mod1);
            hash2[i]=binpow(arr[i-1]+k2,h2,mod2);
            hash1[i]=hash1[i]^hash1[i-1];
            hash2[i]=hash2[i]^hash2[i-1];
        }
    }
    pair<long long,long long> xor_range(long long l,long long r)
    {
        long long h1=hash1[r]^hash1[l-1];
        long long h2=hash2[r]^hash2[l-1];
        return make_pair(h1,h2);
    }
};
void solve()
{
    long long n,q;
    cin>>n>>q;
    vector<long long>v;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        v.push_back(x);
    }

    Xor_Hash h(v);

    for(long long i=1;i<=q;i++)
    {
        long long l,r;
        cin>>l>>r;
        auto ans=h.xor_range(l,r);
        if(ans.first==0 && ans.second==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}