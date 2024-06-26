#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
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
    string s;
    cin>>s;
    long long n=s.length();

    const long long mod=998244353;
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long len)->long long{
        if(len<0)
        return 0;
        if(i==n)
        {
            if(len==0)
            return 1;
             
             return 0;
        }

        if(dp[i][len]!=-1)
        return dp[i][len];
        long long res=0;
        if(s[i]=='(')
        {
            res=(res%mod+f(i+1,len+1)%mod)%mod;
        }
        else if(s[i]==')')
        {
            res=(res%mod+f(i+1,len-1)%mod)%mod;
        }
        else
        {
            res=(res%mod+f(i+1,len-1)%mod)%mod;
            res=(res%mod+f(i+1,len+1)%mod)%mod;
        }

        return dp[i][len]= res;
    };

    long long x=f(0,0);

    cout<<x<<endl;
}