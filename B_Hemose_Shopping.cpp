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
void solve(int);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t = 1;
    cin >> t;
    int count=1;
    while (t--)
    {
        solve(count++);
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
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
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

        parent[ulp_v]=ulp_u;

        size[ulp_u]+=size[ulp_v];
    }
};
void solve(int c)
{
    int n,x;

    cin>>n>>x;

    vector<int>arr(n);

    DSU d(n);
    map<int,vector<pair<int,int>>>mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        int j=i+x;

        while(j<n && d.findUlp(i)!=d.findUlp(j))
        {
            // debug(i,j);
            d.unionBySize(i,j);
            j++;
        }
    }

    if(is_sorted(all(arr)))
    {
        cout<<"YES"<<endl;
        return;
    }
    

    for(int i=0;i<n;i++)
    {
        mp[d.findUlp(i)].push_back({arr[i],i});
    }

    vector<int>v(n);

    for(auto it:mp)
    {
        auto vv=(it.second);
        sort(all(vv));

        vector<int>x;
        for(auto itt:vv)
        {
            x.push_back(itt.second);

        }
        sort(all(x));
        int j=0;
        for(auto i:vv)
        {
            v[x[j++]]=i.first;
        }
    }
    if(is_sorted(all(v)))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}