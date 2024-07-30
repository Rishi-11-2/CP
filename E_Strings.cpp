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
    long long N;
    cin>>N;
    vector<long long>cost(N+1);
    for(long long i=0;i<N;i++)
    cin>>cost[i];
    
    vector<string>arr(N);
    for(long long i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    long long dp[N][2];
 
    // initializing dp array for first string
    dp[0][0] = 0;
    dp[0][1] = cost[0];
 
    // getting array of reversed strings
    string revStr[N];
    for (long long i = 0; i < N; i++)
    {
        revStr[i] = arr[i];
        reverse(revStr[i].begin(), revStr[i].end());
    }
 
    string curStr;
    long long curCost;
 
    // looping for all strings
    for (long long i = 1; i < N; i++)
    {
        // Looping twice, once for string and once
        // for reversed string
        for (long long j = 0; j < 2; j++)
        {
            dp[i][j] = (long long)(1e18);
 
            // getting current string and current
            // cost according to j
            curStr = (j == 0) ? arr[i] : revStr[i];
            curCost = (j == 0) ? 0 : cost[i];
 
            // Update dp value only if current string
            // is lexicographically larger
            if (curStr >= arr[i - 1])
                dp[i][j] = min(dp[i][j], dp[i-1][0] + curCost);
            if (curStr >= revStr[i - 1])
                dp[i][j] = min(dp[i][j], dp[i-1][1] + curCost);
        }
    }
 
    // getting minimum from both entries of last index
    long long res = min(dp[N-1][0], dp[N-1][1]);
 
    cout<<((res == (long long)(1e18))? -1 : res)<<endl;

    
}