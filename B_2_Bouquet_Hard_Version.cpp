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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n,m;
    cin>>n>>m;
    long long arr[n];
    vector<pair<long long,long long >>v;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long c[n];
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(long long i=0;i<n;i++)
    {
        long long cc=m/arr[i];
        cc=min(c[i],cc);
        long long zz=cc*arr[i];
        res=max(res,zz);
        v.push_back({arr[i],c[i]});
    }
    sort(all(v));
    // for(long long i=0;i<n;i++)
    // debug(v[i].first,v[i].second);
    // debug(res);
   for(long long i=1;i<n;i++)
   {
      long long diff=abs(v[i].first-v[i-1].first);
      if(diff>1)
      {
        continue;
      }
      long long x=m/v[i-1].first;
      x=min(x,v[i-1].second);
      
      long long y=x*v[i-1].first;

      long long dd=m-y;
      dd=dd/v[i].first;

      dd=min(dd,v[i].second);

      long long z=dd*v[i].first;

      long long xx=y+z;
    //   debug(xx,dd);
      res=max(res,xx);

      long long di=m-xx;
      dd=v[i].second-dd;
      xx+=min({dd,x});
    //   debug(xx);
      res=max(res,xx);

   }
   cout<<min(res,m)<<endl;
}