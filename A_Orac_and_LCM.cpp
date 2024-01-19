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
long long binpow(long long a,long long b)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    long long m=(long long)(1e5);
    vector<long long>isPrime(m+1,1);
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
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i])
        primes.push_back(i);
    }
    long long res=1;
    map<long long,long long >mp;
    for(auto it:primes)
    {
        vector<long long>v;
        for(long long i=0;i<n;i++)
        {
            long long count=0;
            while(arr[i]%it==0)
            {
                arr[i]/=it;
                count++;
            }
            v.push_back(count);
        }
        sort(all(v));
        if((long long)(v.size())>1)
        {
            // debug(it,v[1]);
            res=res*(binpow(it,v[1]));
        }
        
    }
    for(int i=0;i<n;i++)
    mp[arr[i]]++;
    for(auto it:mp)
    {
        if(it.second>=n-1)
        res=res*it.first;
    }
    cout<<res<<endl;
}
