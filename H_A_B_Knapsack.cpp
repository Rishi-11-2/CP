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
void solve()
{
    long long n,m,s,A,B;
    cin>>n>>m>>s>>A>>B;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    long long b[m];
    for(long long i=0;i<m;i++)
    cin>>b[i];
    
    sort(a,a+n,greater<long long>());
    sort(b,b+m,greater<long long>());


    vector<long long>prefixB(m,0);
    prefixB[0]=b[0];
    for(long long i=1;i<m;i++)
    {
        prefixB[i]=prefixB[i-1]+b[i];
    }


    vector<long long>prefixA(n,0);

    prefixA[0]=a[0];

    for(long long i=1;i<n;i++)
    {
        prefixA[i]=prefixA[i]+a[i];
    }
    long long x=(s/A);
    long long res=0;
    long long sum=0;
    for(long long i=0;i<=min(x,n);i++)
    {
        long long y=s-i*A;
        long long z=min((y/B),m);
        long long zz=0;
        if(z>=1)
        {
            zz=prefixB[z-1];
        }
        res=max(res,sum+zz);
        if(i<n)
        sum+=a[i];
    }
    cout<<res<<endl;
}