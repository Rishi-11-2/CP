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
void solve(int);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    int c=0;
    while (t--)
    {
        solve(++c);
    }
}
void solve(int tt)
{
    long long n,k;
    cin>>n>>k;


    long long a[n+1];

    long long s=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        s=s^a[i];
    }

    vector<long long>adj[n+1];
    for(long long i=1;i<n;i++)
    {
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<long long>value(n+1,0);

    long long flag=0;
    long long flag1=0;
    function<void(long long,long long)>f=[&](long long u,long long p)->void{

        value[u]=a[u];
        for(long long v:adj[u])
        {
            if(v!=p)
            {
                f(v,u);
                value[u]=value[u]^value[v];
            }
        }
        if((s^value[u])==value[u] )
        {
            flag=1;
        }
        if((value[u]==s) && (u!=1))
        {
            value[u]=0;
            flag1++;
        }
    };
    f(1,-1);
    if(flag==1 || ((flag1>=2) &&  (k>2)))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    } 
}