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
    int n,m;
    cin>>n>>m;

    set<int>adj[n+1];

    vector<int>indegree(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        int prev=-1;
        for(int j=1;j<n;j++)
        {
            int y;
            cin>>y;

            if(prev!=-1)
            {
                if(adj[prev].find(y)==adj[prev].end())
                indegree[y]++;
                adj[prev].insert(y);
            }
            prev=y;
        }
    }

    queue<int>q;

    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            // debug(i);
            q.push(i);
        }

    }
    int count=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        count++;
        // debug(u);
        for(int v:adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0)
            q.push(v);
        }
    }

    if(count!=n)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;

    
}