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
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    vector<vector<long long>>dp(n+1,vector<long long>((1LL<<n),-1));
    function<long long(long long,long long)>f=[&](long long i,long long mask)->long long{

        if(i==n)
        {
            long long s1=0;
            long long s2=0;
            // debug(mask);
            for(long long i=0;i<n;i++)
            {
                if(mask&(1LL<<i))
                {
                    s1+=arr[i];
                }
                else
                {
                    s2+=arr[i];
                }
            }
            return max(s1,s2);
        }

        if(dp[i][mask]!=-1)
        return dp[i][mask];

        long long res=(long long)(1e12);
        res=min(res,f(i+1,mask));
        res=min(res,f(i+1,mask|(1LL<<i)));

        return dp[i][mask]= res;
    };

    long long ans=f(0,0);
    cout<<ans<<endl;
}