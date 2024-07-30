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
    long long n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    vector<int>dp(n+3,-1);
    function<long long(long long)>f=[&](long long i)->long long{
        if(i>n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        long long res;
        if(s[i-1]=='C')
        {
            res= (long long)(1e9);
        }
        else if(s[i-1]=='W')
        {
            res=1+f(i+1);
        }
        else
        {
            for(long long k=1;k<=m;k++)
            {
                res=min(res,f(i+k));
            }
        }
        return dp[i]= res;

    };

    long long ans=(long long)(1e9);
    for(long long i=1;i<=m;i++)
    {
        ans=min(ans,f(i));
    }

    if(ans<=k)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}