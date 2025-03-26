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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve(int );
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t = 1;
    cin >> t;
    int count=0;
    while (t--)
    {
        solve(++count);
    }
}
void solve(int c)
{
    int n,m;
    cin>>n>>m;

    // if(c==18)
    // {
    //     cout<<n<<" "<<m<<endl;
    // }
    vector<pair<int,int>>adj[n+1];

    map<pair<int,int>,int>mp;
    int flag=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;

        string s;
        cin>>s;
        
        // if(c==18)
        // {
        //     cout<<u<<" "<<v<<" "<<s<<endl;
        // }

        int t=0;
        if(s=="crewmate")
        t=1;

        if(u>v)
        swap(u,v);
        if(mp.count({u,v}))
        {
            if(mp[{u,v}]!=t)
            {
                flag=1;
            }
        }
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }

    if(flag)
    {
        cout<<-1<<endl;
        return;
    }
    int res=0;
    vector<int>dp(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(dp[i]!=-1)
        continue;
        queue<int>q;
        q.push(i);
        dp[i]=0;
        int count=0;
        int cc=0;
        while(!q.empty())
        {
            auto u=q.front();
            q.pop();
            cc++;
            if(dp[u]==0)
            count++;
            for(auto [v,f]:adj[u])
            {
                int new_f=0;
                if(dp[u]==f)
                new_f=1;

                if(dp[v]!=-1)
                {
                    if(dp[v]==new_f)
                    continue;
                    cout<<-1<<endl;
                    return;
                }


                q.push(v);
                dp[v]=new_f;
            }
        }
        res+=max(count,cc-count);
    }

    
    cout<<res<<endl;
}