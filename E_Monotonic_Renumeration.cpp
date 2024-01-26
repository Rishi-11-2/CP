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
long long binpow(long long a,long long b,long long mod)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}
void solve()
{
    /* basically we have to find the number of components .A component is defined
    as the segment in which the end point and the start point have same value
    We need to find the number of components because if the end and start value are
    equal than there can be only one case. All these components will be independent will have two
    choices either to be equal to value of the previous component or to be one greater than
    the previous component*/
    long long n;
    cin>>n;
    set<long long>s;
    long long arr[n];
    map<long long,long long>last;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        last[arr[i]]=i;
    }
    
   long long i=0;
   long long c=1;
   const long long mod=998244353;
   while(i<n)
   {
      long long j=i;
      long long l=last[arr[i]];
      while(j<=l)
      {
        //  debug(j,l);
         l=max(l,last[arr[j]]);
         j++;
      }
    //   debug(i,j);
      i=j;
      if(i<n)
      c++;
   }

  cout<<binpow(2,c-1,mod)<<endl;


}