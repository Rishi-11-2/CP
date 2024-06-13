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
class DSU{

    public:
    vector<int>size;
    vector<int>parent;
    DSU(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }

    int findUlp(int node)
    {
        if(node==parent[node])
        return node;

        return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findUlp(u);
        int ulp_v=findUlp(v);

        if(size[ulp_v]>size[ulp_u])
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
void solve()
{
    int n,m;

    cin>>n>>m;

    DSU d(n);

    vector<string>res;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        int u,v;
        cin>>u>>v;
        if(s=="union")
        {
            d.unionBySize(u,v);
        }
        else
        {
            int ulp_u=d.findUlp(u);
            int ulp_v=d.findUlp(v);
            if(ulp_u==ulp_v)
            {
                res.push_back("YES");
            }
            else
            {
                res.push_back("NO");
            }
        }
    }

    for(auto it:res)
    cout<<it<<endl;
}