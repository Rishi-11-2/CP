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
long long m=(long long)(2e5)+10;
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
void solve()
{
    long long n;
    cin>>n;

    long long arr[n];
    vector<long long>dp(m+1,0),mp(m+1,0);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }

    // dp[i]: maximum size of the array if we include i
    long long res=0;
    for(long long i=1;i<=m;i++)
    {
        dp[i]+=mp[i];
        for(long long j=2*i;j<=m;j+=i)
        {
            dp[j]=max(dp[i],dp[j]);
        }
    }
    for(long long i=1;i<=m;i++)
    {
        res=max(res,dp[i]);
    }
    cout<<n-res<<endl;
}