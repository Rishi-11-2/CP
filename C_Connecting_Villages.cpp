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
vector<long long>countM;
vector<long long>isPrimes;
void init()
{
    long long m=(long long)(1e7);
    isPrimes.assign(m+1,1);
    isPrimes[0]=isPrimes[1]=0;
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrimes[i])
        {
            for(long long j=i*i;j<=m;j+=i)
            isPrimes[j]=0;
        }
    }

    countM.assign(m+1,0);
    for(long long i=1;i<=m;i++)
    {
        countM[i]=countM[i-1]+isPrimes[i];
    }

    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t;
    init();
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
    long long x=countM[n]-countM[(n/2)];
    if(n<=3)
    x--;
    cout<<x<<"\n";
}