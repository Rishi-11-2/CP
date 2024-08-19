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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,m,k;
    cin>>n>>m>>k;

    long long w;
    cin>>w;

    long long g[w];

    for(long long i=0;i<w;i++)
    cin>>g[i];


    long long grid[n+1][m+1];
    long long grid1[n+1][m+1];
    for(long long i=0;i<=n;i++)
    {
        for(long long j=0;j<=m;j++)
        {
            grid[i][j]=0;
            grid1[i][j]=0;
        }
    }
    vector<long long>v;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            grid1[i][j]=min({i,n-i+1,k,n-k+1})*min({k,m-j+1,j,m-k+1});
            // if(i==1 || j==1||i==n||j==m)
            // grid1[i][j]--;
            // else if((i+k)<=n && (j+k)<=m)
            // grid1[i][j]--;
            // cout<<grid[i][j]<<" ";
            
            v.push_back(grid1[i][j]);
        }
        
        // cout<<endl;
    }


    sort(all(v));
    reverse(all(v));
    sort(g,g+w,greater<long long>());
    long long ans=0;
    for(long long i=0;i<w;i++)
    {
        ans+=(g[i]*v[i]);
    }
    cout<<ans<<endl;
}