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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
class Set_Hash{
    // xor hasing cannot be used as we need to compare multiset, not set
    private:
    const long long mod1=999999937;
    const long long mod2=999999929;
    const long long k1=(long long)(1e7)+1;
    const long long k2=(long long)(1e4)+3;
    const long long h1=37;
    const long long h2=41;
    long long binpow(long long a,long long b,long long mod)
    {
        long long res=1;
        while(b>0)
        {
            if(b&(1LL))
            {
                res=((res)*(a))%mod;
            }
            a=(a%mod*a%mod)%mod;
            b>>=1LL;
        }
        return res;
    }
    public:
    long long n;
    vector<long long>arr;
    vector<long long>hash1,hash2;
    Set_Hash(vector<long long>&v)
    {
        n=(long long)v.size();
        arr=v;
        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        build();
    }
    void build()
    {
        for(long long i=1;i<=n;i++)
        {
            hash1[i]=binpow((arr[i-1]+k1),h1,mod1);
            hash1[i]=(hash1[i]+hash1[i-1])%mod1;
            hash2[i]=binpow((arr[i-1]+k2),h2,mod2);
            hash2[i]=(hash2[i]+hash2[i-1])%mod2;
        }
    }

    pair<long long,long long>getHash(long long l,long long r)
    {
        // 1 based indexing
        long long ans1=hash1[r];
        long long ans2=hash2[r];
        ans1-=hash1[l-1];
        ans2-=hash2[l-1];

        ans1=(ans1%mod1+mod1)%mod1;
        ans2=(ans2%mod2+mod2)%mod2;

        return make_pair(ans1,ans2);
    }
};
void solve()
{
    long long n,q;
    cin>>n>>q;
    vector<long long> a(n),b(n);

    for(long long i=0;i<n;i++)
    cin>>a[i];
    for(long long i=0;i<n;i++)
    cin>>b[i];
    
    Set_Hash s1(a);
    Set_Hash s2(b);

    for(long long i=1;i<=q;i++)
    {
        long long l,r,L,R;
        cin>>l>>r>>L>>R;

        if(s1.getHash(l,r)==s2.getHash(L,R))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}