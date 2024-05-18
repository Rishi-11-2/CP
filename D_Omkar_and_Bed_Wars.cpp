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
    long long dp[n+1][4][4];
    memset(dp,-1,sizeof(dp));
    long long a=-1;
    long long b=-1;
    function<long long(long long,long long,long long)>f=[&](long long i,long long prev,long long sprev)->long long{

        if(i==n-1)
        {
            long long res=(long long)(1e9);
            // debug(prev,sprev,a,b);
            if((sprev!=0 || prev!=0) && (prev!=0 || a!=0) && (a!=0 || b!=0) )
            {
                if(s[n-1]=='L')
                {
                    res=min(res,0LL);
                }
                else
                {
                    res=min(res,1LL);
                }
            }
            if((sprev!=1 || prev!=1) && (prev!=1 || a!=1) && (a!=1 || b!=1) )
            {
                if(s[n-1]=='R')
                {
                    res=0LL;
                }
                else
                {
                    res=min(res,1LL);
                }
            }
            return res;
        }
        if(dp[i][prev][sprev]!=-1)
        return dp[i][prev][sprev];
        long long res=(long long)(1e9);
        if(prev!=0 || sprev!=0)
        {
            if(s[i]=='L')
            {
                res=min(res,f(i+1,0,prev));
            }
            else
            {
                res=min(res,1+f(i+1,0,prev));
            }
        }
        if(prev!=1 || sprev!=1)
        {
            if(s[i]=='R')
            {
                res=min(res,f(i+1,1,prev));
            }
            else
            {
                res=min(res,1+f(i+1,1,prev));
            }
        }
        return dp[i][prev][sprev]= res;
    };
    long long res=(long long)(1e9);
    // LL
     a=0;
     b=0;
    long long x1=f(2,b,a);
    if(s[0]!='L')
    x1++;
    if(s[1]!='L')
    x1++;
    res=min(res,x1);

    //LR
    memset(dp,-1,sizeof(dp));
    a=0;
    b=1;

    long long x2=f(2,b,a);
    if(s[0]!='L')
    x2++;
    if(s[1]!='R')
    x2++;
    res=min(res,x2);

    // RL
    memset(dp,-1,sizeof(dp));

    a=1;
    b=0;

    long long x3=f(2,b,a);
    if(s[0]!='R')
    {
        x3++;
    }
    if(s[1]!='L')
    {
        x3++;
    }
    res=min(res,x3);

    // RR
    memset(dp,-1,sizeof(dp));

    a=1;
    b=1;

    long long x4=f(2,b,a);
    if(s[0]!='R')
    {
        x4++;
    }
    if(s[1]!='R')
    x4++;
    res=min(res,x4);

    // dp.assign(vector<vector<vector<long long>>>(n+1,vector<vector<long long>>(4,vector<long long>(4,-1))));
    cout<<res<<endl;

}