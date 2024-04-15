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
    long long arr[n+2];

    for(long long i=1;i<=n;i++)
    cin>>arr[i];

    vector<long long>dp(n+2,-1);
    function<long long(long long)>f=[&](long long i)->long long{

        if(i>n)
        return 0;

       if(dp[i]!=-1)
       {
        return dp[i];
       }
        
        long long res=1;
        // debug(i);
        // res=max(res,f(i+1));
        for(long long j=i+i;j<=n;j+=i)
        {
            if(arr[j]>arr[i])
            {
                res=max(res,1+f(j));
            }
        }
        return dp[i]= res;
    };
    long long x=0;
    for(int i=1;i<=n;i++)
    {
        x=max(x,f(i));
    }
    cout<<x<<endl;
}