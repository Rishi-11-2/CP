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

    vector<vector<int>>v;

    v.push_back({1,1});
    v.push_back({n,n});

   int d=1;
   for(int i=1;i<=n-2;i++)
   {
      if(i%2)
      {
         v.push_back({1+d,1});
      }
      else
      {
        v.push_back({n,n-d});
      }
      d++;
   }

   for(auto &it:v)
   {
    if(it[0]==n-1 && it[1]==1)
    {
        it[0]=1;
        it[1]=n-1;
    }
   }

   for(auto it:v)
   {
    cout<<it[0]<<" "<<it[1]<<endl;
   }
   cout<<endl;
}