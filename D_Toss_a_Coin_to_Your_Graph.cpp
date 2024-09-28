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
    long long n,m,k;
    cin>>n>>m>>k;

    long long arr[n+1];
    for(long long i=1;i<=n;i++)
    cin>>arr[i];

    vector<long long>adj[n+1];
    for(long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    
    function<long long(long long)>f=[&](long long mid)->long long{
        vector<long long>temp_adj[n+1];
        vector<long long>indegree(n+1,0);
        for(long long i=1;i<=n;i++)
        {
            for(long long v:adj[i])
            {
                if(arr[i]<=mid && arr[v]<=mid)
                {
                    temp_adj[i].push_back(v);
                    indegree[v]++;
                }
            }
        }
        queue<long long>q;
        for(long long i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<long long>topoS;
        while(!q.empty())
        {
            long long u=q.front();
            q.pop();
            topoS.push_back(u);
            for(long long v:temp_adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        long long sz=(long long)topoS.size();
        if(sz!=n)
        {
            return 1;
        }

        vector<long long>dp(n+1,0);
        for(auto u:topoS)
        {
            for(long long v:temp_adj[u])
            {
                dp[v]=max(dp[v],dp[u]+1);
            }
        }
        long long maxm=*max_element(all(dp));
        if(maxm>=(k-1))
        {
            return 1;
        }
        return 0;
    };
    long long low=INT_MAX;
    long long high=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        low=min(low,arr[i]);
        high=max(high,arr[i]);
    }
    long long res=-1;
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    cout<<res<<endl;
}