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

    map<int,int>mp;
    int root=-1;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[i]=y;
        if(x==-1)
        {
            root=i;
            continue;
        }
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    set<int>ans;
    function<void(int,int)>f=[&](int u,int p)->void{
        int res=mp[u];
        for(int v:adj[u])
        {
            if(v==p)
            continue;
            
            f(v,u);
            if(mp[v]==0)
            {
                res=0;
            }
        }
        if(res==1)
        {
            ans.insert(u);
        }
    };

   f(root,0);
    if((int)(ans.size())==0)
    {
        cout<<-1<<endl;
        return;
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}