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
const long long m=(long long)(1e7)+1;
vector<long long>isPrime(m+1,1);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;

    isPrime[0]=0;
    isPrime[1]=0;
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i])
        {
            for(long long j=i*i;j<=m;j+=i)
            {
                isPrime[j]=0;
            }
            // v.push_back
        }
    }
    // for(long long i=2;i<=m)
    cin >> t;
    
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;
    vector<long long>primes;
    
    for(long long i=2;i<=n;i++)
    {
        if(isPrime[i] )
        primes.push_back(i);
    }

    long long m=(long long)primes.size();


    long long j=m-1;
    long long count=0;
    for(long long i=1;i<=n;i++)
    {
        if((i*2)>n)
        break;

        while(j>=0 && (i*primes[j])>n)
        {
            j--;
        }
        count+=(j+1);
    }

    cout<<count<<endl;



}