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

    long long a[n],b[n];
    long long s=0;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        s+=b[i];
    }

    if(s%3)
    {
        cout<<-1<<endl;
        return;
    }
    

    // vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(2000,vector<long long>(2000,-1)));


    vector<vector<long long>>dp(510,vector<long long>(510,0));
    for(long long x=0;x<=501;x++)
    {
        for(long long y=0;y<=501;y++)
        {
            if(x==y && (s-(x+y))==x)
            dp[x][y]=0;
            else
            dp[x][y]=(long long)(1e9);
        }
    }

    for(long long i=n-1;i>=0;i--)
    {
        vector<vector<long long>>ndp(510,vector<long long>(510,0));
        for(long long x=0;x<=501;x++)
        {
            for(long long y=0;y<=501;y++)
            {
                long long res=(long long)(1e9);

                if(a[i]==1)
                {
                    if((x+b[i])<=500)
                    res=min(res,dp[x+b[i]][y]);

                    if((y+b[i])<=500)
                    res=min(res,1+dp[x][y+b[i]]);

                    res=min(res,1+dp[x][y]);
                }

                else if(a[i]==2)
                {
                    if((x+b[i])<=500)
                    res=min(res,1+dp[x+b[i]][y]);

                    if((y+b[i])<=500)
                    res=min(res,dp[x][y+b[i]]);

                    res=min(res,1+dp[x][y]);
                }

                else
                {
                    if((x+b[i])<=500)
                    res=min(res,1+dp[x+b[i]][y]);

                    if((y+b[i])<=500)
                    res=min(res,1+dp[x][y+b[i]]);

                    res=min(res,dp[x][y]);
                }

                ndp[x][y]=res;

            }
        }

        dp=ndp;
    }
    long long ans=dp[0][0];


    if(ans==(long long)(1e9))
    {
        ans=-1;
    }
    cout<<ans<<endl;


}