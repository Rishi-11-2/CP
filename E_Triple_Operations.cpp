#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
const long long m=(long long)(2e5)+1;
long long dp[m+1];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    dp[1]=1;
    dp[2]=1;
    for(long long i=3;i<=m;i++)
    {
        dp[i]=(dp[i/(3LL)]+1);
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long l,r;
    cin>>l>>r;

    long long ans=0;
    long long minm=INT_MAX;
    for(long long i=l;i<=r;i++)
    {
        ans+=dp[i];
        minm=min(minm,dp[i]);
    }
    ans+=minm;
    cout<<ans<<endl;

}