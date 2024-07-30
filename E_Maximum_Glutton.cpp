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
    long long n,x,y;
    cin>>n>>x>>y;

    vector<pair<long long,long long>>v1;
    vector<pair<long long,long long>>v2;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v1.push_back({x,y});
        v1.push_back({y,});
    }
    vector<map<pair<long long,long long>,long long>>dp(n+1);
    function<long long(long long,long long,long long)>f=[&](long long i,long long sx,long long sy)->long long{

        if(i==n)
        {
            return dp[i][{sx,sy}]= 0;
        }
        if(sx>x || sy>y)
        {
            return dp[i][{sx,sy}]= 0;
        }
        if(dp[i].find({sx,sy})!=dp[i].end())
        {
            return dp[i][{sx,sy}];
        }
        long long  res=f(i+1,sx,sy);

        res=max(res,1+f(i+1,sx+v[i].first,sy+v[i].second));

        return dp[i][{sx,sy}]=res;
    };
        function<long long(long long,long long,long long)>f=[&](long long i,long long sx,long long sy)->long long{

        if(i==n)
        {
            return dp[i][{sx,sy}]= 0;
        }
        if(sx>x || sy>y)
        {
            return dp[i][{sx,sy}]= 0;
        }
        if(dp[i].find({sx,sy})!=dp[i].end())
        {
            return dp[i][{sx,sy}];
        }
        long long  res=f(i+1,sx,sy);

        res=max(res,1+f(i+1,sx+v[i].first,sy+v[i].second));

        return dp[i][{sx,sy}]=res;
    };

    long long res1=f(0,0,0);
    long long res2=f1(0,0,0);

    cout<<res<<endl;
}