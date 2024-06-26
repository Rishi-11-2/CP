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
void solve()
{
    long long n,s;
    cin>>n>>s;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];


    long long j=0; 
    vector<long long>dp(s+1,-1);
    long long res=(long long)(1e9);
    for(long long i=0;i<n;i++)
    {
        for(long long k=s;k>=a[i];k--)
        {
            dp[k]=max(dp[k],dp[k-a[i]]);
        }
        dp[a[i]]=i;

        if(dp[s]>=j)
        {
            res=min(res,i-dp[s]+1);
            j=dp[s]+1;
        }
    }

    if(res==(long long)(1e9))
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<res<<endl;
    }
}