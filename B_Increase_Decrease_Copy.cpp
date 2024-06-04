#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

    long long a[n];

    for(long long i=0;i<n;i++)
    cin>>a[i];

    long long b[n+1];

    for(long long i=0;i<=n;i++)
    cin>>b[i];

    long long x=b[n];

    long long diff=(long long)(1e10);
    long long bb=-1;

    long long flag=0;
    for(long long i=0;i<n;i++)
    {
        long long d1=abs(a[i]-x);
        long long d2=abs(b[i]-x);
        if(d1<diff)
        {
            diff=d1;
            bb=a[i];
        }
        if(d2<diff)
        {
            diff=d2;
            bb=b[i];
        }
        if(a[i]>=x &&  b[i] <=x)
        {
            flag=1;
        }
        if(b[i]>=x && a[i]<=x)
        {
            flag=1;
        }
    }

    vector<long long>v;
    for(long long i=0;i<n;i++)
    v.push_back(a[i]);

    v.push_back(bb);

    // for(auto it:v)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    long long res=0;
    long long m=n;
    if(flag)
    m--;
    for(long long i=0;i<=m;i++)
    {
        // debug(abs(v[i]-b[i]));
        res+=abs(b[i]-v[i]);
    }

    cout<<res+1<<endl;
}