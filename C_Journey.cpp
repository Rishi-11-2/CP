#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    
        solve();
    
}
void solve()
{
    int n,m,t;
    cin>>n>>m>>t;
    vector<pair<int,int>>adj[n+1];
    vector<pair<int,int>>radj[n+1];
    for(int i=1;i<=m;i++)
    {   
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        radj[v].push_back({u,wt});
    }

    vector<vector<int>>dp(n+1,vector<int>(n+1,(int)(1e9+1)));
    function<void(int,int)>f=[&](int u,int len)->void{
        for(auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(dp[v][len+1]>dp[u][len]+wt)
            {
                dp[v][len+1]=dp[u][len]+wt;
                f(v,len+1);
            }
        }
    };
    dp[1][1]=0;
    f(1,1);
    int answer=0;
    for(int i=n;i>=1;i--)
    {
        if(dp[n][i]<=t)
        {
            answer=i;
            break;
        }
    }
    cout<<answer<<endl;
    vector<int>v;
    int node=n;
    while(answer>0)
    {
        v.push_back(node);
        for(auto it:radj[node])
        {
            if(dp[node][answer]==dp[it.first][answer-1]+it.second)
            {
                // cout<<"hi"ss<<endl;
                node=it.first;
                // break;
            }
        }
                answer--; 
    }
    reverse(all(v));
    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;

}