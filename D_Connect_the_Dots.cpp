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
class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    int n;
    DSU(int nn)
    {
        n=nn;
        parent.assign(n+1,0);
        size.assign(n+1,1);
        for(int i=1;i<=n;i++)
        {
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
        if(ulp_u==ulp_v)
        return;
        
        if(size[ulp_v]>size[ulp_u])
        swap(ulp_v,ulp_u);
        
        size[ulp_u]+=size[ulp_v];
        parent[ulp_v]=ulp_u;
    }
};
void solve()
{
    int n,m;
    cin>>n>>m;
    DSU d(n);
    map<int,map<int,int>>mp;
    for(int i=1;i<=m;i++)
    {
        int a,k,d;
        cin>>a>>d>>k;
        mp[a][d]=max(mp[a][d],k);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            int position=i;
            int k=mp[position][j];
            while(k>0 && (position+j)<=n)
            {
                d.unionBySize(position,position+j);
                mp[position][j]=0;
                k--;
                position+=j;
                k=max(k,mp[position][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(d.findUlp(i)==i);
    }
    cout<<ans<<endl;
}