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
    long long n;
    cin>>n;

    long long m=(long long)(1e5);

    vector<bool>isPrime(m+1,1);

    isPrime[0]=isPrime[1]=0;

    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i])
        {
            for(long long j=i*i;j<=m;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }

    vector<long long>primes;
    set<long long>pp;

    for(long long i=2;i<=m;i++)
    {
        // if((i*i)>(long long)(1e10))
        // break;
        if(isPrime[i])
        {
            primes.push_back(i*i);
            pp.insert(i*i);
        }
    }
    // debug((long long)(1e10)-primes.back());

    long long mm=(long long)(primes.size());
    n-=4;
    // debug(primes[0]);
    // cout<<(long long)(primes.size())<<endl;
    for(long long k=mm;k>=1;k--)
    {

        long long z=n-primes[k];

        if(z<=0)
        continue;
        
        if(pp.find(z)!=pp.end() && z!=primes[k])
        {
            cout<<"Yes"<<endl;
            return;
        }
    }

    cout<<"No"<<endl;

    
}