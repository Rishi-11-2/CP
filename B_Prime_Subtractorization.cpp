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
void solve(long long );
const long long m=(long long)(1e7)+10;
vector<long long>isPrime(m+1,1);
vector<long long>dp(m+1,0);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    isPrime[1]=isPrime[0]=0;
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i]==1)
        {
            for(long long j=i*i;j<=m;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    dp[5]=2;
    for(long long i=6;i<=m;i++)
    {
        dp[i]=dp[i-1];
        if(isPrime[i])
        {
            if(isPrime[i-2])
            {
                dp[i]++;
            }
        }
    }
    long long count=1;
    while (t--)
    {
        solve(count++);
    }
}
void solve(long long c)
{
    long long n;
    cin>>n;
    cout<<"Case #"<<c<<": ";
    cout<<dp[n]<<endl;
}