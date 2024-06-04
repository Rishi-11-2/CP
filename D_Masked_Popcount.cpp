#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
        solve();
}
long long countSetIthBit(long long N, long long i) {
    long long cycleLength = 1LL << (i + 1); // 2^(i+1)
    long long fullCycles = (N + 1) / cycleLength;
    long long remainder = (N + 1) % cycleLength;

    long long count = fullCycles * (1LL << i); // fullCycles * 2^i
    // debug(count,i);
    count += max(0LL, remainder - (1LL << i)); // remainder - 2^i

    return count;
}
void solve()
{
    long long n,m;
    cin>>n>>m;

    const long long mod=998244353;
    long long res=0;
    for(long long i=0;i<61;i++)
    {
        if((m&(1LL<<i))!=0)
        {
            long long diff=countSetIthBit(n,i);
            // debug(i,diff);
            // long long x=(1LL<<i);
            // diff=(diff%mod*x%mod)%mod;
            res=(res%mod+diff%mod)%mod;
        }
    }
    cout<<res<<endl;
}