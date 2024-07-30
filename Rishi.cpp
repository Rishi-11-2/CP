#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
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
       #ifndef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); 
       freopen("output.txt","w",stdout);
  #endif

       //Your Code

  #ifndef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
  #endif

        solve();
}
class RSA{
    public:
    string s;
    long long public_key;
    long long private_key;
    long long mod;
    RSA(string &a)
    {
        s=a;
        build();
    }
    long long extended_gcd(long long a,long long b,long long &x,long long &y)
    {
        if(b==0)
        {
            x=1;
            y=0;
            return a;
        }
        long long x1;
        long long y1;
        long long g=extended_gcd(b,a%b,x1,y1);
        x=y1;
        y=x1-(a/b)*y1;
        return g;
    }
    long long mod_inverse(long long a,long long mod)
    {
        long long x,y;
        long long g=extended_gcd(a,mod,x,y);
        long long ans=(x%mod+mod)%mod;
        return ans;
    }
    long long binpow(long long a,long long b,long long mod)
    {
        long long res=1;
        a=a%mod;
        while(b>0)
        {
            if(b&(1LL))
            {
                res=(res%mod*a%mod)%mod;
                // debug(res,a);
            }
            a=(a%mod*a%mod)%mod;
            b=b>>1LL;
        }
        return res;
    }
    void build()
    {
        long long p=999999733;
        long long q=2;
        long long phi=(p-1)*(q-1);
        long long n=p*q;
        // long long lambda=(euler_toitent)*(__gcd(p-1,q-1));
        mod=n;
        public_key=phi-1;
        debug(mod);
        // debug(public_key);
        // public_key=phi-1;
        private_key=mod_inverse(public_key,phi);
        debug(private_key);
    }

    long long encrypt(long long num)
    {
        return binpow(num,public_key,mod);
    }
    long long decrypt(long long num)
    {
        return binpow(num,private_key,mod);
    }
};

void solve()
{
    long long n;
    cin>>n;
    string s="hello";
    RSA r(s);
    long long x=r.encrypt(n);
    long long y=r.decrypt(x);
    cout<<y<<endl;
    // debug(x,y,r.public_key,r.private_key);
}