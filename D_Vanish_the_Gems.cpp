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
bool cmp(pair<long long,long long>&a,pair<long long,long long>&b)
{
    if(a.first==b.first);
    return a.second<b.second;

    return a.first>b.first;
}
void solve()
{
    long long n,m;
    cin>>n>>m;

    vector<pair<long long,long long>>v;
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        sum+=y;
        v.push_back({x,y});
    }
    sort(all(v),cmp);
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long count)->long long{

        if(count>=n)
        {
            return 0;
        }
        if(i==n)
        {
            return (long long)(1e12);
        }
        if(dp[i][count]!=-1)
        return dp[i][count];

        long long res=f(i+1,count);

        res=min(res,v[i].second+f(i+1,min(n,count+v[i].first+1)));

        return dp[i][count]= res;
    };

    long long res=f(0,0);
    // debug(res);
    res=min(res,sum);
    cout<<(sum-res)<<endl;
}