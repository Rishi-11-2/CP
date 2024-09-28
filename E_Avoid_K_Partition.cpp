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
void solve()
{
    const long long mod=998244353;
    long long n,k;
    cin>>n>>k;

    vector<long long>dp(n+1,0);

    vector<long long>pref(n+1,0);

    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        pref[i]=pref[i-1]+x;
    }

    map<long long,long long>mp;

    long long sum=1;
    dp[0]=1;
    mp[0]=1;
    /* dp[i] -> indicaes the number of ways of dividing array[0..i] into segments with one partition at i*/
    for(long long i=1;i<=n;i++)
    {
        dp[i]=sum;

        if(mp.find(pref[i]-k)!=mp.end())
        {
            dp[i]=(dp[i]%mod-mp[pref[i]-k]%mod+mod)%mod;
        }
        sum=(sum%mod+dp[i]%mod)%mod;
        mp[pref[i]]=(mp[pref[i]]%mod+dp[i]%mod)%mod;
    }
    // for(int i=0;i<=n;i++)
    // cout<<dp[i]<<" ";
    // cout<<endl;
    cout<<dp[n]<<endl;
}