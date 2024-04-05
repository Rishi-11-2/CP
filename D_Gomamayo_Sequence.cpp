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
    string s;
    cin>>s;

    long long cost[n];
    for(long long i=0;i<n;i++)
    cin>>cost[i];

    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(4,vector<long long>(4,-1)));


    function<long long(long long,long long,long long)>f=[&](long long i,long long prev,long long count)->long long{

        if(count>1)
        {
          return (long long)(1e15);
        }
        if(i==n)
        {
            if(count==1)
            return 0;
            return (long long)(1e15);   
        }

        if(dp[i][prev+1][count]!=-1)
        return dp[i][prev+1][count];
        long long newCount=count;
        long long newPrev=s[i]-'0';
        if(prev==newPrev)
        newCount++;
        long long res=(long long)(1e15);
        res=f(i+1,newPrev,newCount);
        long long newCount2=count;
        if(1-newPrev==prev)
        newCount2++;
        res=min(res,f(i+1,1-newPrev,newCount2)+cost[i]);
        return dp[i][prev+1][count]= res;
    };

    long long x=f(0,-1,0);
    cout<<x<<endl;
}