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
    long long t = 1;
    // cin >> t;
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
    map<char,long long>mp;
    mp['R']=0;
    mp['P']=1;
    mp['S']=2;
    long long win[3][3];
    for(long long i=0;i<3;i++)
    {
        for(long long j=0;j<3;j++)
        {
            if(i==0 && j==2)
            {
                win[i][j]=1;
            }
            else if(i==2 && j==1)
            {
                win[i][j]=1;
            }
            else if(i==1 && j==0)
            {
                win[i][j]=1;
            }
            else
            {
                win[i][j]=0;
            }
        }
    }
    vector<vector<long long>>dp(n+3,vector<long long>(4,-1));
    function<long long(long long,long long)>f=[&](long long i,long long j)->long long{
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j+1]!=-1)
        return dp[i][j+1];
        long long res=0;

        for(long long k=0;k<3;k++)
        {
            if(k==j)
            continue;
            if(win[k][mp[s[i]]]==0 && (k!=mp[s[i]]))
            continue;
            // debug(win[k][mp[s[i]]]);
            res=max(res,win[k][mp[s[i]]]+f(i+1,k));
        }

        return dp[i][j+1]= res;
    };
    long long ans=f(0,-1);

    cout<<ans<<endl;
}