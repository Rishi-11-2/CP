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

    vector<int>adj[n+1];

    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int c=0;
    int r=-1;
    for(int i=1;i<=n;i++)
    {
        int sz=(int)(adj[i].size());
        // debug(i,sz);
        if(sz>=3)
        {
            r=i;
            c++;
        }
    }
    if(c>1)
    {
        cout<<"No"<<endl;
        return;
    }
    vector<vector<int>>res;
    function<void(int,int,int)>f=[&](int u,int p,int s)->void{

        int flag=0;

        for(int v:adj[u])
        {
            if(v==p)
            continue;
            flag=1;
            f(v,u,s);
        }

        if(!flag)
        {
            res.push_back({s,u});
        }
    };
    if(r==-1)
    r=1;
    f(r,0,r);

    cout<<"Yes"<<endl;
    cout<<(int)(res.size())<<endl;

    for(auto it:res)
    {
        cout<<it[0]<<" "<<it[1];
        cout<<endl;
    }
}