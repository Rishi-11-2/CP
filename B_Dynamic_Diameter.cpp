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

        solve();
}
void solve()
{
    int n;
    cin>>n;
    

    vector<int>adj[n+2];
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int dd=-1;
    int res=-1;

    int diameter=-1;
    int flag=1;
    vector<int>dist(n+1,0);
    function<void(int,int,int)>f=[&](int u,int par,int d)->void{

        dist[u]=max(dist[u],d);
        if(d>dd && flag)
        {
            dd=d;
            res=u;
        }
        if(d>diameter)
        {
            diameter=d;
        }
        for(int v:adj[u])
        {
            if(v==par)
            continue;
            
            f(v,u,d+1);
        }
    };

    f(1,0,0);
    flag=0;
    diameter=-1;
    f(res,0,0);
    int res1=-1;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==diameter)
        {
            res1=i;
            break;
        }
    }
    dist[res]=diameter;
    f(res1,0,0);

    for(int i=1;i<=n;i++)
    {
        if(dist[i]==diameter)
        {
            cout<<diameter+1<<endl;
        }
        else
        {
            cout<<diameter<<endl;
        }
    }
}