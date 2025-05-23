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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invarlong longs)
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
        if(b&1)
        {
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}
void solve()
{
    long long n;
    cin >> n;

    long long r = n % 4;
    const long long mod = (long long)(1e9) + 7;
    long long s = 0;

    if (r == 0)
    {
        long long y = (n / 2 - 1) % mod;
        s = (y * y) % mod;
    }
    else if ((r == 2)  && (n>2))
    {
        long long y = (n - 2) % mod;
        y = (y * y) % mod;
        long long inv4 =binpow(4,mod-2,mod); 
        s = (y * inv4) % mod;
        s = (s + 1) % mod;
        long long yy=(n/4)+1;
        s=(s%mod+yy%mod)%mod;
    }
    else if (r == 3)
    {
        long long y = ((n - 1) / 2) % mod;
        s = (y * y) % mod;
    }
    else if(n>1 && ((n%4)==1))
    {
        // if()
        long long y = ((n - 3) / 2) % mod;
        s = (y * y) % mod;
        s = (s + ((n - 1) % mod)) % mod;
        long long yy=(n/4);
        s=(s%mod+yy%mod)%mod;
    }

    // debug(s);
    cout << s << '\n';
}
