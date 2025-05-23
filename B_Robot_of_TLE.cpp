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
    solve();
}
void solve()
{
    long long n;
    cin>>n;
  

    vector<set<int>>adj(n+1);


    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;

        v.push_back({x,y});
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;

            if(v[i].first==v[j].first || v[i].second==v[j].second)
            {
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }

    vector<int>vis(n+1,0);

    auto f=[&](int u,auto&& f)->void{

        vis[u]=1;
        for(int v:adj[u])
        {
            if(!vis[v])
            {
                f(v,f);
            }
        }
    };

    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            f(i,f);
            count++;
        }
    }

    cout<<count-1<<endl;

}