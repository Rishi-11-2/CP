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
int flag=1;
vector<int>adj[(int)(2e5)+1];
set<int>f(int u,int p,vector<int>&colors)
{
    set<int>s;
    for(int v:adj[u])
    {
        if(v==p)
        continue;

        auto it=f(v,u,colors);

        if((int)(it.size())>1)
        {
            flag=0;
            return it;
        }
        s.insert(colors[v]);
    }
    s.insert(colors[u]);
    return s;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
    }
    vector<pair<int,int>>v;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>colors(n+1,0);

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        colors[i]=x;
    } 


    int a=-1;
    int b=-1;
    for(int i=0;i<n-1;i++)
    {
       if(colors[v[i].first]!=colors[v[i].second])
       {
          a=v[i].first;
          b=v[i].second;
       }
    }
    if(a==-1)
    a=1;
    if(b==-1)
    b=1;
    flag=1;
    auto it1=f(a,-1,colors);

    if(flag==1)
    {
        cout<<"YES"<<endl;
        cout<<a<<endl;
        return;
    }   
    flag=1;
    auto it2=f(b,-1,colors);   


    if(flag==1)
    {
        cout<<"YES"<<endl;
        cout<<b<<endl;
        return;
    }   
    
    cout<<"NO"<<endl;
}