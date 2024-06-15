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
long long modInverse(long long a,long long b)
{
    return binpow(a,b-2,b);
}
void solve()
{
   long long a,b,c;
   cin>>a>>b>>c;

   long long n=max(a,max(b,c));
   vector<long long>fact(n+1,0);
   vector<long long>ifact(n+1,0);

   fact[0]=1;

    long long mod= 998244353;

   for(long long i=1;i<=n;i++)
   {
       fact[i]=(fact[i-1]%mod*i%mod)%mod;
   }

   ifact[n]=modInverse(fact[n],mod);

   for(long long i=n-1;i>=0;i--)
   {
      ifact[i]=(ifact[i+1]%mod*(i+1)%mod)%mod;
   }


   function<long long(long long,long long)>f=[&](long long n,long long r)->long long{

      long long x = (ifact[n-r]%mod*ifact[r]%mod)%mod;

      x=(x%mod*fact[n]%mod)%mod;

      return x;
   };

   long long resa=0;
   long long resb=0;
   long long resc=0;

   for(long long i=0;i<=min(a,b);i++)
   {
      long long x=((f(a,i)%mod*f(b,i)%mod)%mod*(fact[i]%mod))%mod;

      resa+=x;
   }
    for(long long i=0;i<=min(c,b);i++)
   {
      long long x=((f(c,i)%mod*f(b,i)%mod)%mod*(fact[i]%mod))%mod;

      resb+=x;
   }
   for(long long i=0;i<=min(c,a);i++)
   {
      long long x=((f(c,i)%mod*f(a,i)%mod)%mod*(fact[i]%mod))%mod;

      resc+=x;
   }

//    debug(resa,resb,resc);
   long long res=((resa%mod)*(resb%mod))%mod;
   res=((res%mod)*(resc%mod))%mod;
   cout<<res<<endl;
}