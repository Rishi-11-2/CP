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
    long long t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];

   vector<long long>prefix(n,0);

   for(long long i=0;(i)<n;i++)
   {
      long long rem=(n-i)-1;

      if(i)
      {
        prefix[i]+=prefix[i-1];
      }

      if((i+1)<n)
      prefix[i+1]++;

      arr[i]+=prefix[i];
      if((i+1)<n && arr[i] < rem)
      {
        prefix[arr[i]+i+1]--;
      }

      arr[i]-=rem;
      arr[i]=max(0LL,arr[i]);
   }


   for(long long i=0;i<n;i++)
   {
      cout<<(arr[i])<<" ";
   }
   cout<<endl;
}