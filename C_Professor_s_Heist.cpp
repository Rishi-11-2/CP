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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
class DSU{
    public:
    vector<long long>size;
    vector<long long>parent;
    long long cc;
    DSU(long long n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        cc=n;
        for(long long i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }

    long long findUlp(long long node)
    {
        if(node==parent[node])
        return node;

       return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);

        if(ulp_u==ulp_v)
        return ;
        cc--;
        if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }
};
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
void solve()
{
    long long n,p;
    cin>>n>>p;

    DSU d(n);
    for(long long i=0;i<p;i++)
    {
        long long x,y;
        cin>>x>>y;
        
        long long j=x;
        long long k=y;
        // debug(j,k);
        while(j<k)
        {
            d.unionBySize(j,k);
            j++;
            k--;
        }
    }
    const long long mod=(long long)(1e9)+7;
    cout<<binpow(26,d.cc,mod)<<endl;
}