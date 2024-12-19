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
    long long n,m;
    cin>>n>>m;

    vector<long long>dp(m+1,-(long long)(1e9));
    vector<long long>count(m+1,0);
    dp[0]=0;

    long long c=0;

    for(long long i=0;i<n;i++)
    {
        long long r;
        cin>>r;

        if(r>0)
        {
            if(r<=c)
            count[r]++;
        }
        else if(r<0)
        {
            r=-r;
            r=c-r;
            if(r>=0)
            {
                count[0]++;
                count[r+1]--;
            }
        }
        else
        {
            for(long long j=1;j<=c;j++)
            {
                count[j]+=count[j-1];
                // cout<<count[j]<<" ";
            }
            // cout<<endl;
            for(long long j=0;j<=c;j++)
            {
                dp[j]+=count[j];
            }
            c++;

            for(long long j=c;j>=1;j--)
            {
                dp[j]=max(dp[j-1],dp[j]);
            }
            count.assign(c+1,0);
        }
    }

    for(long long i=1;i<=c;i++)
    {
        count[i]+=count[i-1];
                // cout<<count[i]<<" ";
    }
    for(long long i=0;i<=c;i++)
    {
        dp[i]+=count[i];
        // debug(i,dp[i]);
    }

    long long ans=*max_element(all(dp));

    cout<<ans<<endl;
}