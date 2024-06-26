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

    string s;
    cin>>s;

    if(n==2)
    {
        cout<<stoi(s)<<endl;
        return;
    }
    vector<vector<long long>>vv;
    for(long long i=0;i+1<n;i++)
    {
        string x=s.substr(i,2);
        vector<long long>v;
        v.push_back(stoi(x));
        for(long long j=0;j<i;j++)
        {
            v.push_back(s[j]-'0');
        }
        for(long long j=i+2;j<n;j++)
        {
            v.push_back(s[j]-'0');
        }
        vv.push_back(v);
    }

    long long idx=0;
    vector<long long>dp(n+1,-1);
    function<long long(long long)>f=[&](long long i)->long long{

        if(i==n-2)
        {
            return vv[idx][i];
        }  
        if(dp[i]!=-1)
        return dp[i];
        long long res=vv[idx][i]+f(i+1);
        res=min(res,vv[idx][i]*f(i+1));

        return dp[i]= res;
    };

    long long res=(long long)(1e18);
    for(long long i=0;i<(long long)(vv.size());i++)
    {
        idx=i;
        dp.assign(n+1,-1);
        res=min(res,f(0));
    }

    cout<<res<<endl;


}