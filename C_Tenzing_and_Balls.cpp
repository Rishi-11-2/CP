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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
     
    vector<int>dp(n+1,1);
    map<int,int>minm;
    for(int i=0;i<n;i++)
    {
        minm[arr[i]]=INT_MAX;
    }
    dp[0]=0;
    dp[1]=1;
    minm[arr[0]]=dp[0];
    /* dp[i]= min(dp[i-1]+1,dp[j1],dp[j2],dp[j3], ..dp[jk])*/
    /* here j1 , j2 , j3 are the previous matching indices */
    /* dp[ j2 ]=min(dp[j1], dp[j2-1]+1)
       dp[j3]=min(dp[j2],dp[j1],dp[j3-1]+1)

       dp[j4]=min(dp[j3],dp[j2],dp[j1],dp[j4-1]+1)

       ...

       dp[jk]=min(dp[j1],dp[j2],dp[j3],...,dp[j(k-1)-1],dp[jk-1]+1)


       so we can store the minimum of dp[j1], dp[j2], dp[j3 ],.. dp[jz] for dp[j(z+1)] 



    */
    for(int i=2;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+1,minm[arr[i-1]]);
        minm[arr[i-1]]=min(minm[arr[i-1]],dp[i-1]);
    }
    cout<<n-dp[n]<<endl;
}