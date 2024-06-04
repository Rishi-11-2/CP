#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    long long n,m,k;
    cin>>n>>m>>k;

    long long a[n];
    long long maxm=0;
    long long idx=-1;
    multiset<long long,greater<long long>>s;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            if((a[i]-a[i-1])>maxm)
            {
                maxm=a[i]-a[i-1];
                idx=i;
            }
            s.insert(a[i]-a[i-1]);
        }
    }

    // long long maxm=*s.begin();

    s.erase(s.begin());

    long long smax=-(long long)(1e18);
    if(!s.empty())
    smax=*s.begin();

    long long d[m];
   for(long long i=0;i<m;i++)
   cin>>d[i];

   long long f[k];

   for(long long i=0;i<k;i++)
   cin>>f[i];

   
   multiset<long long>ss;
   for(auto it:d)
   {
    ss.insert(it);
   }

   long long mid=(a[idx]+a[idx-1])/2;
   long long res=maxm;
//    debug(idx,mid);
   for(long long i=0;i<k;i++)
   {
    //   if(mid-f[i]<0)
    //   continue;
      auto it=ss.lower_bound(mid-f[i]);
      if(it!=ss.end())
      {
        // debug()
        long long x=f[i]+*it;
        if(x<=a[idx] && x>=a[idx-1])
        res=min(res,max(abs(a[idx]-(f[i]+*it)),abs((*it+f[i])-a[idx-1])));
      }

      auto it1=ss.upper_bound(mid-f[i]);

      if(it1!=ss.begin())
      {
        it1--;
        long long x=f[i]+*it1;
        if(x<=a[idx] && x>=a[idx-1])
        res=min(res,max(abs(a[idx]-(f[i]+*it1)),abs((*it1+f[i])-a[idx-1])));
      }

   }

   cout<<max(res,smax)<<endl;
}