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
    long long n,k;

    cin>>n>>k;

    vector<pair<long long,long long>>v;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long k1)->long long{
        if(k1<0)
        {
            return (long long)(1e18);
        }
        if(k1==0)
        {
            return 0;
        }
        if(i==n)
        {
            return (long long)(1e18);
        }
        if(dp[i][k1]!=-1)
        return dp[i][k1];
        long long res=f(i+1,k1);
        long long a=v[i].first;
        long long b=v[i].second;
        long long cost=0;
        for(long long j=1;j<=min(v[i].first+v[i].second,k1);j++)
        {
            cost+=min(a,b);
            if(a>b)
            {
                a--;

            }
            else
            {
                b--;
            }
            res=min(res,cost+f(i+1,k1-j));
        }
        return dp[i][k1]= res;
    };

    long long res=f(0,k);

    if(res==(long long)(1e18))
    res=-1;

    cout<<res<<endl;
}