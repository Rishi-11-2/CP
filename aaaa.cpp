#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
  long long binpow(long long long long b,long long mod)
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
       string s;
       int n;
       int primes;
       vector<int> hashPrimes = {1000000009, 100000007};
       const int base = 1001;
       vector<vector<int>> hashValues;
       vector<vector<int>> powersOfBase;
       vector<vector<int>> inversePowersOfBase;
       Hashing(string a){
            primes = (int)(hashPrimes.size());
            hashValues.resize(primes);
            powersOfBase.resize(primes);
            inversePowersOfBase.resize(primes);
            s = a;
            n = s.length();
            for(int i = 0; i < primes; i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                 powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = inverse(powersOfBase[i][n], hashPrimes[i]);
           for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = ((inversePowersOfBase[i][j + 1]%hashPrimes[i])*(base%hashPrimes[i]))%hashPrimes[i];
           }
       }
       for(int i = 0; i < primes; i++) {
           hashValues[i].resize(n);
           for(int j = 0; j < n; j++){
              int val=(s[j]-'a'+1LL);
               hashValues[i][j] = (val%hashPrimes[i] * powersOfBase[i][j]%hashPrimes[i]) % hashPrimes[i];
               hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
       }
   }
    vector<int> substringHash(int l, int r){
       vector<int> hash(primes);
       for(int i = 0; i < primes; i++){
         int val1 = hashValues[i][r];
             int val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
         hash[i] = ((val1-val2+hashPrimes[i])%hashPrimes[i]*inversePowersOfBase[i][l]%hashPrimes[i])%hashPrimes[i];
       }
    return hash;
    }
  };
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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

}