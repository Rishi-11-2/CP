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
    long long n,m;
    cin>>n>>m;

    long long grid[n][m];

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        cin>>grid[i][j];
    }

    
    long long a[]={-1,1};
    long long b[]={-1,1};
    
    long long ans=0;
    for(long long k1=0;k1<2;k1++)
    {
        for(long long k2=0;k2<2;k2++)
        {
            map<long long,long long>mp;
            for(long long i=0;i<n;i++)
            {
                for(long long j=0;j<m;j++)
                {
                    long long x=(i-1)*a[k1]+(j-1)*b[k2];

                    mp[grid[i][j]-x]++;
                }
            }
            for(auto it:mp)
            {
                // debug(it.first,it.second);
                ans=max(ans,it.second);
            }
        }
    }


    cout<<(n*m-ans)<<endl;
}