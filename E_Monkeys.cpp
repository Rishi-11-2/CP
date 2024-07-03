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
    long long n,m;
    cin>>n>>m;

    map<long long,long long>left;
    map<long long,long long>right;

    multiset<long long>adj[n+1];

    for(long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;

       left[i+1]=x;
       right[i+1]=y;
       if(x!=-1)
       {
         adj[i+1].insert(x);
         adj[x].insert(i+1);  
       }
       if(y!=-1)
       {
         adj[i+1].insert(y);
         adj[y].insert(i+1);
       }
    }
    auto tleft=left;
    auto tright=right;
    vector<pair<long long,long long>>v1;
    for(long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;
        v1.push_back({x,y});
        if(y==1)
        {
            adj[x].erase(adj[x].find(left[x]));
            adj[left[x]].erase(adj[left[x]].find(x));
           left[x]=-1;
        }
        else
        {
            adj[x].erase(adj[x].find(right[x]));
            adj[right[x]].erase(adj[right[x]].find(x));
           right[x]=-1;
        }
    }


    vector<long long>vis(n+1,0);
    vector<long long>ans(n+1,-2);

    function<void(long long,long long)>f=[&](long long u,long long d)->void{

        // if(vis[u])
        // return;
        vis[u]=1;
        ans[u]=d;
         
        for(auto v:adj[u])
        {
            if(!vis[v])
            f(v,d);
        }
    };

    f(1,-1);

    for(long long i=m-1;i>=0;i--)
    {
        long long x=v1[i].first;
        long long y=v1[i].second;
        if(y==1)
        {
            left[x]=tleft[x];
            adj[x].insert(left[x]);
            adj[left[x]].insert(x);
            if(ans[x]!=-2 && ans[left[x]]==-2)
            {
                f(left[x],i);
            }
            else if(ans[left[x]]!=-2 && ans[x]==-2)
            {
                f(x,i);
            }
        }
        else
        {
            right[x]=tright[x];
            adj[x].insert(right[x]);
            adj[right[x]].insert(x);
            if(ans[x]!=-2 && ans[right[x]]==-2)
            {
                f(right[x],i);
            }
            else if(ans[right[x]]!=-2 && ans[x]==-2)
            {
                f(x,i);
            }
            // for(long long i=1;i<=n;i++)
            // cout<<ans[i]<<" ";
            // cout<<endl;
        }

    }

    for(long long i=1;i<=n;i++)
    cout<<ans[i]<<endl;
}