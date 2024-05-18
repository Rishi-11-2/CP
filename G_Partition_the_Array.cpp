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
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];

    
   // flag 0  (1)
    // flag 1 (-1)

    vector<vector<long long>>dp(n+1,vector<long long>(3,-1));
    function<long long(long long,long long)>f=[&](long long i,long long flag)->long long{
        if(i==n)
        {
            return 0;
        }

        if(dp[i][flag]!=-1)
        return dp[i][flag];
        long long sign=1;
        if(flag==1)
        sign =-1;
        long long x=0;
        long long res=0;

        /* 1 10 100 1000  1000 ...  1000..00(30 zeroes)   0     1 10  100 1000 ..... 1000.0000(30 zeroes)   */

        /* at max size of the window will be 61. because  we have 30 bits . we need to divide it into 3 segments(suppose) 
        */
        for(long long j=i;j<min(100+i,n);j++)
        {
            x=x|arr[j];
            long long y=sign*x;
            res=max(res,y+f(j+1,1-flag));
        }


        return dp[i][flag]= res;
    };

    long long x=f(0,0);
    cout<<x<<endl;
}