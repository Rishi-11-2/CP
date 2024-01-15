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
vector<long long>count1;
void solve();
void sieve()
{
long long m=(long long)(1e7);
    vector<bool>isPrime(m+1,1);
    vector<int>CPrime(m+1,1);
    isPrime[0]=isPrime[1]=0;
    CPrime[0]=CPrime[1]=0;
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i])
        {
            for(long long j=i*i;j<=m;j+=i)
            {
                isPrime[j]=0;
                CPrime[j]--;
            }
        }
    }
    count1.assign(m+1,0);
    for(int i=2;i<=m;i++)
    {
        if(isPrime[i])
        {
            int x=i;
            while(x<=m)
            {
                
            }
        }
    }
    for(long long i=2;i<=m;i++)
    {
        count1[i]=count1[i-1]+CPrime[i];
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t;
    sieve();
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
    debug(count1[2],count1[3],count1[4],count1[5],count1[6]);
    cout<<count1[n]-1<<'\n';
}