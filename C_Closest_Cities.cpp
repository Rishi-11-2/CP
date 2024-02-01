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
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    map<pair<int,int>,int>mp;
    mp[{1,2}]=1;
    for(int i=2;i<=n-1;i++)
    {
        int x=arr[i]-arr[i-1];
        int y=arr[i+1]-arr[i];
        if(x<y)
        {
            mp[{i,i-1}]=1;
        }
        else
        {
            // debug(i,i+1);
            mp[{i,i+1}]=1;
        }
    }
   mp[{n,n-1}]=1;
    
    for(int i=1;i<=n-1;i++)
    {
        if(mp.find({i,i+1})==mp.end())
        {
            mp[{i,i+1}]=arr[i+1]-arr[i];
        }
    }
    for(int i=n;i>=2;i--)
    {
        if(mp.find({i,i-1})==mp.end())
        {
            mp[{i,i-1}]=arr[i]-arr[i-1];
        }
    }
    vector<int>forward(n+1,0);
    // debug(mp[{3,2}]);
    for(int i=2;i<=n;i++)
    {
        forward[i]=forward[i-1]+mp[{i-1,i}];
    }
    vector<int>backward(n+1,0);
    for(int i=n-1;i>=1;i--)
    {
        backward[i]=backward[i+1]+mp[{i+1,i}];
    }

    // for(auto it:forward)
    // cout<<it<<" ";
    // cout<<endl;

    // for(auto it:backward)
    // cout<<it<<" ";
    // cout<<endl;

    int m;
    cin>>m;
    vector<int>res;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x<y)
        {
            res.push_back(forward[y]-forward[x]);
        }
        else
        {
            res.push_back(backward[y]-backward[x]);
        }
    }

    for(auto it:res)
    cout<<it<<endl;

}