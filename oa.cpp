#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    int n,k;
    cin>>n>>k;
    double p;
    cin>>p;
    double win =p;
    double lose=1-p;
    //(i,j,flag)-> i denotes the first i games where you have won exactly last j games 
    //flag indicates whether you have achieved a win streak of k or not uptill i
    vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(2,-1)));
    function<double(int,int,int)>f=[&](int i,int j,int flag)->double{

        // debug(i,j,flag);
        if(i==n)
        {
            if(flag)
            return (double)1;
            
            return (double)0;
        }
        if(dp[i][j][flag]!=-1)
        return dp[i][j][flag];
        double l=lose*f(i+1,0,flag);
        int newJ=j+1;
        int newFlag=flag;
        if(newJ>=k)
        newFlag=1;
        //  debug(i,j);
        double w=win*f(i+1,newJ,newFlag);

        double res=w+l;
        // debug(res);

        return dp[i][j][flag]= res;
    };

    cout<<f(0,0,0)<<endl;
}