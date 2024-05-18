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
    long long n;
    cin>>n;
    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];

    sort(arr,arr+n);
    // reverse(arr,arr+n);
    const long long mod=(long long)(998244353);
    vector<vector<long long>>dp(n+1,vector<long long>(6001,-1));
    function<long long(long long,long long)>f=[&](long long i,long long s)->long long{

        if(i==n)
        {
            return 0;
        }

        if(dp[i][s]!=-1)
        return dp[i][s];

        // simply take or not take. if we take then we add the sum and also
        // consider the subset which will end at that index
        // if we dont take we simply move forward
        long long res=f(i+1,s);
        long long x=0;
        if(arr[i]>=s)
        {
            x=arr[i];
        }
        else
        {
            long long newS=s+arr[i];
            x=(newS+1)/2;
        }
        
        long long y=(x+f(i+1,s+arr[i]))%mod;
        // we are adding x . this is because it will not be included in this subset
        // but rather there will be subset which will end in ith index and in that subset
        // we will have the x . therefore x is getting added for that subset


        res=(res%mod+y%mod)%mod;
        return dp[i][s]= res;
    };

    long long x=f(0,0);
    cout<<x<<endl;
}