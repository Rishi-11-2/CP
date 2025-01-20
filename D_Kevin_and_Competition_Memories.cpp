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

    long long a[n];

    vector<long long>v;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        if(i)
        {
            v.push_back(a[i]);
        }
    }

    vector<long long>b(m);

    for(long long i=0;i<m;i++)
    cin>>b[i];

   sort(all(v));

   sort(b.begin(),b.end());

    vector<long long>num(m,0);
   long long i=0;
   long long j=0;

   while(j<m)
   {
       while(i<n-1 && b[j]>v[i])
       {
          i++;
       }
       num[j]=(n-1)-i;
       j++;
   }

   vector<long long>kevin(m,0);

   vector<long long>ans(m+1,0);
   for(long long i=0;i<m;i++)
   {
       if(a[0]>=b[i])
       {
         kevin[i]=1;

         ans[1]+=1;
       }
       else
       {
         ans[1]+=1+num[i];
       }
   }

//    debug(ans[1]);

//    for(long long i=0;i<m;i++)
//    {
//        cout<<num[i]<<" ";
//    }
//    cout<<endl;

   vector<long long>unsolved;
   long long cs=0;
   for(long long i=0;i<m;i++)
   {
      if(kevin[i]==1)
      {
         cs++;
      }
      else{
        unsolved.push_back(num[i]);
      }
    //   cout<<kevin[i]<<" ";
   }
//    cout<<endl;

   sort(all(unsolved));

   long long cus=(long long)unsolved.size();

   for(long long k=2;k<=m;k++)
   {
      long long d=(m/k);

      long long res=0;
      res+=cs/k;

      d-=(cs/k);

      long long rem=cs%k;
    //   debug(res,k);
      if(d>0)
      {
        long long j=k-rem-1;
        while((j)<cus)
        {
            res+=unsolved[j]+1;
            j+=k;
        }
      }

      ans[k]=res;
    //   debug(k,res);
   }

   for(long long k=1;k<=m;k++)
   {
    cout<<ans[k]<<" ";
   }

   cout<<endl;
   
}