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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
class DSU{

    public:
    vector<long long>parent;
    vector<long long>size;

    long long n;
    DSU(long long nn)
    {
        n=nn;
        parent.resize(n+1);
        size.resize(n+1);

        for(long long i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }

    long long findUlp(long long node)
    {
        if(node==parent[node])
        return node;

        return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);

        if(ulp_u==ulp_v)
        return ;

        if(size[ulp_v]>size[ulp_u])
        swap(ulp_u,ulp_v);

        size[ulp_u]+=size[ulp_v];
        parent[ulp_v]=ulp_u;
    }
};
void solve()
{

    long long n;
    cin>>n;

    long long arr[n+1];

    DSU d(n+1);
    for(long long i=1;i<=n;i++)
    {
        cin>>arr[i];
        d.unionBySize(i,arr[i]);
    }


    long long res=0;
    vector<long long>ans;
    set<long long>s;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        // debug(d.findUlp(arr[x]));
        auto node=d.findUlp(arr[x]);
        if(s.find(node)==s.end())
        {
            res+=(d.size[node]);
            s.insert(node);
        }

        ans.push_back(res);
    }

    for(auto it:ans)
    cout<<it<<" ";

    cout<<endl;

}