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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<vector<int>>v;

    vector<int>x;
    x.push_back(k);
    v.push_back(x);

    for(int i=1;i<n;i++)
    {
        vector<int>vv;
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i)
            {
                vv.push_back(v[i-1][0]);
            }
            else
            {
                vv.push_back(v[i-1][j-1]^v[i-1][j]);
            }
        }
        v.push_back(vv);
    }
    for(auto it:v)
    {
        for(auto i:it)
        cout<<i<<" ";
        cout<<endl;
    }

    // int maxm=0;

    // for(int i=1;i<=n;i++)
    // {
    //     int x=1;

    //     while((x)<=i)
    //     {
    //         x=x*2;
    //     }
    //     maxm=max(maxm,x-i);
    // }
    // cout<<maxm<<endl;
}