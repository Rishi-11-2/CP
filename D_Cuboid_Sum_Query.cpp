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
    long long n;
    cin>>n;
    long long grid[n*n][n];
    for(long long i=0;i<n*n;i++)
    {
        for(long long j=0;j<n;j++)
        cin>>grid[i][j];
    }
    long long A[n][n][n];
    long long idx=0;
    for(long long i=0;i<n*n;i+=n)
    {
        long long j1=0;
        for(long long j=i;j<i+n;j++)
        {
            for(long long k=0;k<n;k++)
            {
                A[idx][j1][k]=grid[j][k];
            }
            j1++;
        }
        idx++;
    }
    // debug(A[0][0][0]);
    // for(long long i=0;i<n;i++)
    // {
    //     for(long long j=0;j<n;j++)
    //     {
    //         for(long long k=0;k<n;k++)
    //         // cout<<A[i][j][k]<<" ";
    //         // cout<<endl;
    //     }

    // }
    vector<vector<vector<long long>>>pre(n+1,vector<vector<long long>>(n+1,vector<long long>(n+1,0)));
    pre[0][0][0] = A[0][0][0];

    long long L=n;
    long long C=n;
    long long R=n;
    for (long long i = 1; i < L; i++)
        pre[i][0][0] = pre[i - 1][0][0] + A[i][0][0];
 
    for (long long i = 1; i < R; i++)
        pre[0][i][0] = pre[0][i - 1][0] + A[0][i][0];
 
    for (long long i = 1; i < C; i++)
        pre[0][0][i] = pre[0][0][i - 1] + A[0][0][i];
 
    for (long long k = 1; k < L; k++) {
        for (long long i = 1; i < R; i++) {
            pre[k][i][0] = A[k][i][0]
                           + pre[k - 1][i][0]
                           + pre[k][i - 1][0]
                           - pre[k - 1][i - 1][0];
        }
    }
    for (long long i = 1; i < R; i++) {
        for (long long j = 1; j < C; j++) {
            pre[0][i][j] = A[0][i][j]
                           + pre[0][i - 1][j]
                           + pre[0][i][j - 1]
                           - pre[0][i - 1][j - 1];
        }
    }
    for (long long j = 1; j < C; j++) {
        for (long long k = 1; k < L; k++) {
            pre[k][0][j] = A[k][0][j]
                           + pre[k - 1][0][j]
                           + pre[k][0][j - 1]
                           - pre[k - 1][0][j - 1];
        }
    }
 
    for (long long k = 1; k < L; k++) {
        for (long long i = 1; i < R; i++) {
            for (long long j = 1; j < C; j++) {
                pre[k][i][j] = A[k][i][j]
 
                               + pre[k - 1][i][j]
                               + pre[k][i - 1][j]
                               + pre[k][i][j - 1]
 
                               - pre[k - 1][i - 1][j]
                               - pre[k][i - 1][j - 1]
                               - pre[k - 1][i][j - 1]
 
                               + pre[k - 1][i - 1][j - 1];
            }
        }
    }

    long long q;
    cin>>q;
    function<long long(long long,long long,long long,long long,long long,long long)>f=[&](long long D,long long E,long long F,long long X,long long Y,long long Z)->long long{
        long long sum = pre[X][Y][Z];
 
    if (D > 0) {
        sum -= pre[D - 1][Y][Z];
    }
    if (E > 0) {
        sum -= pre[X][E - 1][Z];
    }
    if (F > 0) {
        sum -= pre[X][Y][F - 1];
    }
 
    if (D > 0 && E > 0) {
        sum += pre[D - 1][E - 1][Z];
    }
    if (E > 0 && F > 0) {
        sum += pre[X][E - 1][F - 1];
    }
    if (F > 0 && D > 0) {
        sum += pre[D - 1][Y][F - 1];
    }
 
    if (D > 0 && E > 0 && F > 0) {
        sum -= pre[D - 1][E - 1][F - 1];
    }
 
    return sum;
    };
    for(long long i=1;i<=q;i++)
    {
        long long x1,x2,y1,y2,z1,z2;
        cin>>x1>>x2>>y1>>y2>>z1>>z2;
        x1--;
        x2--;
        y1--;
        y2--;
        z1--;
        z2--;
        long long ans=f(x1,y1,z1,x2,y2,z2);

        cout<<ans<<endl;
    }
}