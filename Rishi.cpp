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
void solve(int);
const int m=(int)(1e7)+10;
vector<long long>isPrime(m+1,1);
vector<long long>dp(m+1,0);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
       #ifndef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("substantial_losses_input.txt","r",stdin); 
       freopen("substantial_losses_output.txt","w",stdout);
  #endif

       //Your Code

  #ifndef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
  #endif

    int t;
    cin >> t;
    int count=1;
    while (t--)
    {
        solve(count++);
    }
}
void solve(int c)
{
    cout<<"Case #"<<c<<": ";
    long long w,g,l;
    cin>>w>>g>>l;

    const long long mod=998244353;

    long long a=(w%mod-g%mod+mod)%mod;
    long long b=(2*l+1)%mod;
    // debug(a);
    cout<<(a%mod*b%mod)%mod<<endl;
}