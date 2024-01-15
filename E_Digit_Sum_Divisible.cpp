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
    // cin >> t;
    // while (t--)
    // {
        solve();
}
long long digsum(long long n)
{
    long long sum=0;
    while(n>0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
void solve()
{
    long long n;
    cin>>n;

    map<int,int>mp;
    function<int(int)>f=[&](int i)->int{
      if(i<0)
      return 0;
      if(i==0)
      return 1;

       if(mp.find(i))
       int res=0;
       for(int j=0;j<=9;j++)
       {
          res+=f(i-j);
       }  

       return res;
    };
    long long count=0;
    for(long long i=1;i<=126;i++)
    {
      
         count+=f(i);
    }
    cout<<count<<endl;
}