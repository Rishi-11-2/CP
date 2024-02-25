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
    long long n;
    cin>>n;
    vector<pair<long long,long long>>v;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    vector<vector<long long>>dp(n+1,vector<long long>(3,-1));
    function<long long(long long,long long)>f=[&](long long i,long long flag)->long long{

        if(i==n-1)
        {
            return 0;

        }
        if(dp[i][flag]!=-1)
        return dp[i][flag];
        long long res=f(i+1,0);
        if(flag==0)
        {
            if((v[i].first-v[i].second)>v[i-1].first)
            {
                res=max(res,1+f(i+1,0));
            }
            
        }
         if(flag==1)
        {
            if((v[i].first-v[i].second)>(v[i-1].first+v[i-1].second))
            {
                res=max(res,1+f(i+1,0));
            }
        }
         if((v[i].first+v[i].second)<v[i+1].first)
        {
            // debug(i);
            res=max(res,1+f(i+1,1));
        }
        return dp[i][flag]= res;
    };

    long long x=f(1,0)+2;
    cout<<x<<endl;
}