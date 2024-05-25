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
long long dp[(1<<19)][3];
vector<int>adj[19];
long long f(long long mask,long long flag,long long n)
{
    
        if(dp[mask][flag]!=-1)
        {
           return dp[mask][flag];
        }
        long long res=0;
        long long x=0;
        for(long long i=1;i<=n;i++)
        {
            if(mask&(1LL<<i))
            continue;
            for(long long j:adj[i])
            {
                if(mask&(1<<j))
                continue;
                x=1;
                long long newMask=mask|(1LL<<i);
                newMask=newMask|(1LL<<j);

                long long xx=f(newMask,1-flag,n);

                if(xx==0 && flag==0) // if bob wins and it is bob's turn than he will chose that path 
                return dp[mask][flag]= 0;
                
                if(xx==1 && flag=1) // if alice wins and it is alice's turn than he will chose that path
                return dp[mask][flag]=1;

                /* this is because since both players are playing optimally*/

            }
        }
        if(x==0)
        {
            return 1 -flag;
            // 1 -> Takashi wins
            // 0 -> Aoki wins
        }
        return dp[mask][flag]= res;
}
void solve()
{
    long long n;
    cin>>n;

    vector<pair<long long,long long>>v;
    for(long long i=1;i<=n;i++)
    {
        adj[i].clear();
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            if(i==j)
            continue;
            if(v[i-1].first==v[j-1].first || v[i-1].second ==v[j-1].second)
            {
                adj[i].push_back(j);
            }

        }
    }
    memset(dp,-1,sizeof(dp));
    long long x=f(0,1,n);

    if(x==1)
    {
        cout<<"Takahashi"<<endl;
    }
    else
    {
        cout<<"Aoki"<<endl;
    }
}