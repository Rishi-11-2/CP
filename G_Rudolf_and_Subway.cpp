#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>adj[n+1];

    for(int i=1;i<=m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    int src,dest;
    cin>>src>>dest;

    if(src==dest)
    {
        cout<<0<<endl;
        return;
    }
    set<pair<int,int>>s;
    s.insert({0,src});

    vector<int>dist(n+1,(int)(1e9));
    dist[src]=1;

    while(!s.empty())
    {
        auto it=*s.begin(); 
        s.erase(s.begin());
        int u=it.second;
        int d=it.first;

        for(auto v:adj[u])
        {
            int newD=d;
            if(d!=)
            if(dist[v]>)
        }
    }
}