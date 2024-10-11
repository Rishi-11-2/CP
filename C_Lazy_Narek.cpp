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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,m;
    cin>>n>>m;

    vector<string>v;
    for(long long i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }

    map<char,long long>mp;
    mp['n']=0;
    mp['a']=1;
    mp['r']=2;
    mp['e']=3;
    mp['k']=4;
    vector<vector<long long>>dp(n+1,vector<long long>(6,0));
    for(long long j=0;j<5;j++)
    {
        dp[n][j]=-2*j;
    }

    for(long long i=n-1;i>=0;i--)
    {
        for(long long j=0;j<5;j++)
        {
            long long res=dp[i+1][j];
            long long ans1=0;
            long long ans2=0;
            long long new_j=j;
            for(long long k=0;k<m;k++)
            {
                if(mp.find(v[i][k])!=mp.end())
                {
                    if(mp[v[i][k]]==new_j)
                    {
                        ans1++;
                        new_j=(new_j+1)%5;
                    }
                    else
                    ans2++;
                }
            }
            res=max(res,ans1-ans2+dp[i+1][new_j]);

            dp[i][j]= res;
        }
    }

    long long ans=dp[0][0];

    cout<<ans<<endl;
}