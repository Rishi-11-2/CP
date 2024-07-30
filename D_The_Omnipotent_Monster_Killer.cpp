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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    vector<long long>v(n+1,0);
    for(long long i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    long long maxm=22;
    const long long inf=(long long)(1e18);
    vector<vector<long long>>dp(n+1,vector<long long>(maxm,inf));

    vector<long long>adj[n+1];
    for(long long i=1;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    function<void(long long,long long)>f=[&](long long u,long long p)->void{

        for(long long i=1;i<maxm;i++)
        {
            dp[u][i]=(i*v[u]);
        }  

        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            
            f(v,u);

            for(long long i=1;i<maxm;i++)
            {
                /* if you kill a monster on the vertex u at ith round, you can  kill the monsters at
                adjacent vertices on jth round where j!=i. Now you just need to find the minimum cost of killing all the
                 adjacent monsters in the jth rounds. Number of rounds will always be less than equal to 19(why?)*/
                long long minm=inf;
                for(long long j=1;j<maxm;j++)
                {
                    if(i==j)
                    continue;
                    minm=min(minm,dp[v][j]);
                }
                dp[u][i]+=minm;
            }
        }


    };
    f(1,-1);
    long long ans=*min_element(dp[1].begin(),dp[1].end());
    cout<<ans<<endl;

}