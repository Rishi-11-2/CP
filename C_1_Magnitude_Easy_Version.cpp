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
//(data type to be stored (pair,int ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraint s)
typedef tree < pair<int ,int >, null_type,less<pair<int ,int >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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

    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
     
    vector<vector<int >>dp(n+1,vector<int >(2,0));

    for(int i=1;i<=n;i++)
    {
        dp[i][0]=min(dp[i-1][0]+a[i-1],dp[i-1][1]+a[i-1]);

        dp[i][1]=max(abs(dp[i-1][0]+a[i-1]),abs(dp[i-1][1]+a[i-1]));

        debug(max(dp[i][0],dp[i][1]));
    }

    cout<<max(dp[n][0],dp[n][1])<<endl;
}