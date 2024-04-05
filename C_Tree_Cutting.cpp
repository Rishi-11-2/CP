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
    long long t;
    cin >> t;
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
    for(long long i=1;i<=n-1;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    long long low=1;
    long long high=n;

    long long res=0;

    long long ans=0;
    function<long long(long long,long long,long long)>dfs=[&](long long u,long long par,long long mid)->long long{

        long long count=0;
        for(long long v:adj[u])
        {
            if(v!=par)
            {
                count+=dfs(v,u,mid);
            }
        }
        count++;
        if(count>=mid)
        {
            count=0;
            ans++;
        }
        // debug(u,count);
        return count;
    };
    function<long long(long long)>f=[&](long long mid)->long long{
        ans=0;
        long long s=dfs(1,0,mid);

        if(ans-1>=k)
        return 1;

        return 0;
    };
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(f(mid))
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<res<<endl;
}