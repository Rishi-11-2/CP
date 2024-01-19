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
vector<long long>spf;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long m=100000;
    spf.assign(m+1,0);

    for(long long i=0;i<=m;i++)
    {
        spf[i]=i;

    }
    for(long long i=4;i<=m;i+=2)
    spf[i]=2;
    for(long long i=3;i*i<=m;i++)
    {
        if(spf[i]==i)
        {
            for(long long j=i*i;j<=m;j+=i)
            {
                if(spf[j]==j)
                spf[j]=i;
            }
        }
    }
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
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // debug(spf[2]);
    long long count=0;
    // if((odd==n||even==n) && n>1)
    // count++;
    for(long long i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            for(long long j=0;j<i;j++)
            {
                long long k=j+i;
                long long g=0;
                while(k<n)
                {
                    g=__gcd(g,abs(arr[k]-arr[k-i]));
                    k+=i;
                }
                if(g!=1)
                count++;
            }
        }
    }
    cout<<count<<endl;
}