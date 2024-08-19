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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,x,y;
    cin>>n>>x>>y;

    vector<long long>a;
    vector<long long>b;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }

    // dp[i][j][s] : minimum value of saltiness when we have considered array elements
    // upto j such that the sweetness of all the selected elements equal s and i is the number
    // of elements considered upto index j
    long long m=(long long )(1e4);
    long long dp[n+1][n+1][m+1];
    for(long long i=0;i<=n;i++)
    {
        for(long long j=0;j<=n;j++)
        {
            for(long long s=0;s<=m;s++)
            {
                dp[i][j][s]=(long long)(1e9);
            }
        }
    }
    dp[0][0][0]=0;
    long long res=0;
    for(long long j=0;j<n;j++)
    {
        for(long long i=0;i<=j;i++)
        {
            for(long long s=0;s<=x;s++)
            {
                dp[i][j+1][s]=dp[i][j][s];

                if((s+a[j])<=x)
                { 
                    dp[i+1][j+1][s+a[j]]=min(dp[i+1][j+1][s+a[j]],dp[i][j][s]+b[j]);
                    // if(dp[i+1][j+1][s+a[j]]<=y)
                    // {
                    //     // debug(i,s);
                    //     res=max(res,i+1);
                    // }
                }
            }
        }
    }
    for(long long i=n;i>=0;i--)
    {
        for(long long j=0;j<=x;j++)
        {
            if(dp[i][n][j]<=y)
            {
                cout<<min(i+1,n)<<endl;
                return;
            }
        }
    }
    // debug(res);


}