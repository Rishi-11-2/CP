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
void solve()
{
    string s;
    cin>>s;
    long long n=s.length();

    vector<long long>v(n,0);
    for(long long i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            v[i]=1;
        }
        else
        {
            v[i]=-1;
        }
    }
    vector<long long>prefix(n,0);
    vector<long long>dp(n+2,0);
    long long k=0;
    const long long mod=(long long)(1e9)+7;
    prefix[0] = v[0]; 
        for(long long i = 1; i < n; i++)
        {
            prefix[i] = v[i] + prefix[i - 1];
            // debug(prefix[i]);
        }
        
        map<long long,long long> mp; 
        
        long long ans = 0; 
        long long c=0;
        for(long long i = 1; i <= n; i++) 
        {
            // debug(prefix[i-1]);
            // ans=0;
            if(prefix[i-1] == k) 
                ans=(ans%mod+1LL%mod)%mod;
            
            
            if(mp.find(prefix[i-1] - k) != mp.end())
            {
                ans = (ans%mod+mp[prefix[i-1] - k]%mod)%mod; 
            }
            dp[i]=(ans+c)%mod;
            c=(c%mod+dp[i]%mod)%mod;
            debug(dp[i]);
            mp[prefix[i-1]]++; 
        }
        debug(dp[n],ans);
        long long sum=0;
        for(int i=0;i<=n;i++)
        {
            sum=(sum%mod+dp[i]%mod)%mod;
        }
        cout<<sum<<endl; 
}