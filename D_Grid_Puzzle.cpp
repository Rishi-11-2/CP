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
    vector<vector<int>>dp(n+1,vector<int>(6,-1));
    function<int(int,int)>f=[&](int i,int prev)->int{
        if(i==n)
        {
            return (prev+1)/2;
        }
        // if(dp[i][prev]!=-1)
        // return dp[i][prev];
        if(arr[i]>4)
        {
            return dp[i][prev]= 1+f(i+1,0);
        }
        int res=1+f(i+1,0);
        if(prev>0)
        {
            res=min(res,(max(arr[i],prev)+1)/2+f(i+1,max(0,arr[i]-prev)));
        }
        else
        {
            res=min(res,f(i+1,arr[i]));
        }
        return dp[i][prev]= res;
    };

    int ans=f(0,0);
    cout<<ans<<endl;
}