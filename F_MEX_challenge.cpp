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
    vector<long long>v(n);
    vector<long long>mp(5001,0);
    for(long long i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]>5000)
        continue;
        mp[v[i]]++;
    }
    
    set<long long>s(all(v));
    vector<long long>vv(all(s));

    long long m=0;

    while(mp[m])
    {
        m++;
    }

    long long mm=(long long)vv.size();
    vector<vector<long long>>dp(m+1,vector<long long>(m+1,-1));
    function<long long(long long,long long)>f=[&](long long num,long long mex)->long long{
        if(num==0)
        {
            return (mp[0]-1)*mex;
        }
        if(dp[num][mex]!=-1)
        return dp[num][mex];
        if(mp[num]==0)
        {
            long long res=f(num-1,num);
            return dp[num][mex]=res;
        }
        long long res=f(num-1,mex);
        res=min(res,(mp[num]-1)*mex+num+f(num-1,num));
        return dp[num][mex]=res;
    };

    long long ans=f(m,m);

    cout<<ans<<endl;



}