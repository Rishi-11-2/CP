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
long long f(long long i,long long h,long long amount,vector<long long>&cost,vector<long long>&happy,vector<vector<long long>>&dp,vector<vector<long long>>&sp,long long x)
{
    
        if(i==(long long)(happy.size())-1)
        {
            sp[i][h]=amount;
            if(amount>=cost[i])
            return dp[i][h]= happy[i];
            else
            return dp[i][h]= 0;
        }

        if(dp[i][h]!=-1 && sp[i][h]>=amount)
        return dp[i][h];
        long long a=f(i+1,h,amount+x,cost,happy,dp,sp,x);
        if(amount >= cost[i])
        {
            a=max(a,happy[i]+f(i+1,h+happy[i],amount-cost[i]+x,cost,happy,dp,sp,x));
        }
        sp[i][h]=amount;

       return  dp[i][h]=a;
}
void solve()
{
    long long m,x;
    cin>>m>>x;

    vector<long long>cost;
    vector<long long>happy;

    long long sum=0;
    for(long long i=1;i<=m;i++)
    {
        long long c,h;
        cin>>c>>h;

        sum+=h;
        cost.push_back(c);
        happy.push_back(h);
    }

    long long n=sum;
    vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
    vector<vector<long long>>sp(m+1,vector<long long>(n+1,0));

    long long res=f(0,0,0,cost,happy,dp,sp,x);

    cout<<res<<endl;
}