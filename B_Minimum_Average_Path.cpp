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
    long long n,m;
    cin>>n>>m;

    vector<pair<long long,long long>>adj[n+1];

    for(long long i=1;i<=m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }



    long double low=0.0;
    long double high=(1e2);

    long double eps=1e-4;
    vector<long long>parent(n+1,-1);
    vector<long long>p(n+1,-1);


    function<long long(long double)>f=[&](long double mid)->long long{

        parent.resize(n+1,-1);
        vector<long double>dp(n+1,(1e9));

        dp[1]=0;
        for(long long node=1;node<=n;node++)
        {
            if(dp[node]==1e9)
            continue;
            for(auto v:adj[node])
            {
                long double new_wt=v.second-mid;
                if(dp[v.first]>(dp[node]+new_wt))
                {
                    dp[v.first]=dp[node]+new_wt;
                    parent[v.first]=node;
                }
            }
        }
        if(dp[n]<=0.0)
        return 1;
        return 0;
    };
    while((high-low)>eps)
    {
        long double mid=(low+high)/2.0;

        if(f(mid))
        {
            p=parent;
            high=mid-eps;
        }
        else
        {
            low=mid+eps;
        }
    }

     long long node=n;

     vector<long long>path;

     while(node!=-1)
     {
        path.push_back(node);
        node=parent[node];
     }

     reverse(all(path));

     cout<<(long long)(path.size()-1)<<endl;

     for(auto node:path)
     cout<<node<<" ";
     cout<<endl;
}