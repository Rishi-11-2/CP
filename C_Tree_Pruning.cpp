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
    long long n;
    cin>>n;

    vector<long long>adj[n+1];
    vector<long long>degree(n+1,0);
    for(long long i=1;i<n;i++)
    {
        long long a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<long long>dp(n+1,0);
    vector<long long>parent(n+1,-1);

    function<void(long long,long long)>f=[&](long long u,long long p)->void{
        parent[u]=p;
        if(p!=-1)
        degree[p]++;
        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            
            f(v,u);
            dp[u]+=dp[v]+1;
        }
    };

    f(1,-1);

    function<long long(long long)>f1=[&](long long u)->long long{
        if(degree[u]>0 || u==1)
        return 0;

        long long ans=0;

        long long node=u;

        while(node!=-1)
        {
            ans++;
            node=parent[node];
            if(node==-1)
            break;
            degree[node]--;
            if(degree[node]>0)
            break;
        }

        return ans;

    };
    queue<long long>q;
    q.push(1);

    vector<long long>vis(n+1,0);
    vis[1]=1;
    long long res=dp[1];
    long long ops=0;
    while(!q.empty())
    {
        long long sz=(long long)q.size();
        long long sum=0;
        long long ss=0;
        vector<long long>v;
        for(long long i=1;i<=sz;i++)
        {
            long long u=q.front();
            q.pop();
            v.push_back(u);
            sum+=dp[u];
            for(long long v:adj[u])
            {
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        res=min(res,sum+ops);
        for(auto u:v)
        {
            ops+=f1(u);
        }
    }


    cout<<res<<endl;

}