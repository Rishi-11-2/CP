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
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int>friends;
    queue<int>q;
    vector<int>fd(n+1,(int)(1e9));
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        fd[x]=0;
        friends.push_back(x);
        q.push(x);
    }

    vector<int>adj[n+1];

    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(fd[v]>(fd[u]+1))
            {
                fd[v]=fd[u]+1;
                q.push(v);
            }
        }
    }

    q.push(1);
    vector<int>dist(n+1,(int)(1e9));
    dist[1]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(dist[v]>(dist[u]+1))
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }

    vector<int>leaves;

    function<void(int,int)>f=[&](int u,int p)->void{
        int flag=0;

        for(int v:adj[u])
        {
            if(v==p)
            continue;
            f(v,u);
            flag=1;
        }
        if(!flag)
        leaves.push_back(u);
    };
    f(1,-1);

    for(auto it:leaves)
    {
        if(dist[it]<fd[it])
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}