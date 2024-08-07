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
    cin>>t;
    while(t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }
    vector<long long>isPrime(n+1,1);
    for(long long i=2;i<=n;i++)
    {
        if(isPrime[i])
        {
            for(long long j=i*i;j<=n;j+=i)
            {
               isPrime[j]=0; 
            }
        }
    }

    long long res=1;
    vector<long long>v(n+1,0);
    v.assign(n+1,1);
    // long long count=2;
    v[1]=1;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=2*i;j<=n;j+=i)
        {
            if(v[j]==v[i])
            v[j]++;
        }
    }
    long long minm=*max_element(all(v));
    res=minm;
    cout<<res<<endl;
    for(long long i=1;i<=n;i++)
    {
        cout<<v[i]<<" ";   
    }
    cout<<endl;
}