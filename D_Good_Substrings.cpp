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
  long long binpow(long long a,long long  b,long long mod)
  {
     long long res=1;
     while(b>0)
      {
        if(b&1)
        {
           res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b=b>>1LL;
      }
  return res;
  }
  long long inverse(long long n,long long mod)
   {
      return binpow(n,mod-2,mod);
   }
class Hashing{
    public:
    long long modLength;
    vector<long long>modPrimes={(long long)(1e9+7),(long long)(1e9+9)};
    const long long p=1001;
    vector<vector<long long>>powersOfP;
    vector<vector<long long>>inversePowersOfP;
    vector<vector<long long>>hash;
    long long n;
    string s;
    Hashing(string a)
    {
        s=a;
        n=s.length();
        modLength=modPrimes.size();
        powersOfP.resize(modLength);
        inversePowersOfP.resize(modLength);
        hash.resize(modLength);

        for(long long i=0;i<modLength;i++)
        {
            powersOfP[i].resize(n);
            inversePowersOfP[i].resize(n);
            hash[i].resize(n);
        }

        for(long long i=0;i<modLength;i++)
        {
            powersOfP[i][0]=1;
            for(long long j=1;j<n;j++)
            {
                powersOfP[i][j]=(p%modPrimes[i]*powersOfP[i][j-1]%modPrimes[i])%modPrimes[i];
            }
            inversePowersOfP[i][n-1]=inverse(powersOfP[i][n-1],modPrimes[i]);

            for(long long j=n-2;j>=0;j--)
            {
                inversePowersOfP[i][j]=(p%modPrimes[i]*inversePowersOfP[i][j+1]%modPrimes[i])%modPrimes[i];
            }
            for(long long j=0;j<n;j++)
            {
                long long val=(s[j]-'a'+1);
                long long pref=0;
                if(j>0)
                {
                    pref=hash[i][j-1];
                }
                hash[i][j]=(pref%modPrimes[i]+(val%modPrimes[i]*powersOfP[i][j]%modPrimes[i])%modPrimes[i])%modPrimes[i];

            }
        }
    }

    vector<long long>substringHash(long long l,long long r)
    {
        vector<long long>v;
        for(long long i=0;i<modLength;i++)
        {
            long long val=hash[i][r];

            long long pref=0;
            if(l>0)
            {
                pref=hash[i][l-1];
            }
            val=(val-pref+modPrimes[i])%modPrimes[i];
            val=(val%modPrimes[i]*inversePowersOfP[i][l]%modPrimes[i])%modPrimes[i];

            v.push_back(val);

        }

        return v;
    }
};
void solve()
{
    string s;
    cin>>s;
    long long n=s.length();
    vector<long long>v(26,0);
    string x;
    cin>>x;
    long long m=x.length();
    for(long long i=0;i<m;i++)
    {
        long long  val=(x[i]-'0');
        v[i]=(1-val);
    }
    Hashing h(s);
    long long k;
    cin>>k;
    vector<long long>prefix(n,0);
    prefix[0]=v[s[0]-'a'];
    for(long long i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+v[s[i]-'a'];
    }
    // for(auto it:prefix)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    long long count=0;
    set<vector<long long>>stt;
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<=i;j++)
        {
            long long val=prefix[i];
            if(j>0)
            {
                val-=prefix[j-1];
            }
            if(val<=k)
            {
                auto vvv=h.substringHash(j,i);
                stt.insert(vvv);
            }
        }
    }
    count=(long long)(stt.size());
    cout<<count<<endl;
}