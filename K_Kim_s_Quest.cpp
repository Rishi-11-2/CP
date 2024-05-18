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
vector<long long>arr;
long long dp[(long long)(2e5)+5][3][2][4];
const long long mod=998244353;
long long f(long long i,long long prev1,long long prev2,long long flag,long long n)
{
        if(i==n)
        {
            // debug(flag);
            if(flag==3)
            return 1;
            else
            return 0;
        }
        if(dp[i][prev1][prev2][flag]!=-1)
        return dp[i][prev1][prev2][flag];
        long long res=0;
        res=f(i+1,prev1,prev2,flag,n);
        long long x=arr[i];
        long long y=x+prev1+prev2;
        if(y%2==0|| flag<2)
        {
            int newFlag=min(3LL,flag+1);
            res=(res+f(i+1,x,prev1,newFlag,n))%mod;
        }

        return dp[i][prev1][prev2][flag]= res;
}
void solve()
{
    long long n;
    cin>>n;
    arr.assign(n+1,-1);
    memset(dp,-1,sizeof(dp));
    long long x=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]=arr[i]%2;
    }
        x=(x%mod+f(0,0,0,0,n)%mod)%mod;

    
    // long long flag=0;
    cout<<x<<endl;
}