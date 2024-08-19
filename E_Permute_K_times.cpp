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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,k;
    cin>>n>>k;

    vector<long long>adj[n+1];

    vector<long long>v;
    v.push_back(-1);

    long long maxm=60;
    vector<vector<long long>>parent(maxm+1,vector<long long>(n+1,-1));
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        v.push_back(x);

        // adj[i].push_back(x);
        parent[0][i]=x;
    }

    for(long long i=1;i<=maxm;i++)
    {
        for(long long node=1;node<=n;node++)
        {
            long long node_m=parent[i-1][node];
            if(node_m!=-1)
            {
                parent[i][node]=parent[i-1][node_m];
            }
        }

    }

    function<long long(long long, long long)>f=[&](long long node, long long k)->long long{
        if(k<0)
        return node;
        for(long long i=maxm;i>=0;i--)
        {
            if(k&(1LL<<i))
            {
                node=parent[i][node];
                if(node==-1)
                return node;
            }
        }
        return node;
    };
    vector<long long>arr(n+1);
    for(long long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    for(long long i=1;i<=n;i++)
    {

        long long x=f(v[i],k);
        // debug(x);
        cout<<arr[x]<<" ";
    }
    cout<<endl;


}