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
void solve()
{
    int n;
    cin>>n;


    map<int,vector<int>>adj;
    vector<int>vis(28,1);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        set<int>x;
        for(auto it:s)
        {
            vis[it-'a']=0;
            x.insert(it-'a');
        }
        vector<int>vv(all(x));
        int sz=(int)(vv.size());

        for(int i=0;i<sz-1;i++)
        {
            adj[vv[i]].push_back(vv[i+1]);
            adj[vv[i+1]].push_back(vv[i]);
        }
    }

   function<void(int)>f=[&](int i)->void{

     vis[i]=1;
     for(int v:adj[i])
     {
        if(!vis[v])
        {
            f(v);
        }
     }
   };
    int count=0;
    for(int i=0;i<26;i++)
    {
        if(!vis[i])
        {
            f(i);
            count++;
        }
        // count+=flag;
    }

    cout<<count<<endl;
}