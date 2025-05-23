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
    // cin >> t;
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

    vector<int>vv(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    int res=0;

    for(auto v:adj[1])
    {
        vv[v]=1;
        res++;
    }
    cout<<res<<endl;
    vv[1]=2;
    set<int>s;
    for(int i=2;i<=n;i++)
    {
        if(vv[i]==1)
        {
            res--;
        }
        vv[i]=2;
        int flag=0;
        for(int v:adj[i])
        {
            // if(v==i)
            // continue;
            if(vv[v]==2)
            flag=1;
            if(vv[v]==0)
            {
                res++;
                vv[v]=1;
            }
        }
        if(!flag || (int)s.size()>0)
        {
            s.insert(i);
            vv[i]=1;
            cout<<-1<<endl;
        }
        else
        {
            for(int v:adj[i])
            {
                if(vv[i]==1)
                {
                    vv[v]=1;
                    s.erase(v);
                }
            }
            cout<<res<<endl;
        }
    }
}