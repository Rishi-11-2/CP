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
        {
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}
void solve()
{
    long long n,m;
    cin>>n>>m;
    long long arr[n][m];
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        long long one=0;
        long long zero=0;
        for(long long j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            one++;
            if(arr[i][j]==0)
            zero++;
        }
       long long y=0;
        long long x=0;
        if(one>1)
        {
            x=binpow(2,one);
            x--;
            x-=one;
        }
        if(zero>1)
        {
            y=binpow(2,zero);
            y--;
            y-=zero;
        }
        res=res+x+y;
    }
    for(long long j=0;j<m;j++)
    {
        long long one=0;
        long long zero=0;
        for(long long i=0;i<n;i++)
        {
            if(arr[i][j]==1)
            one++;
            if(arr[i][j]==0)
            zero++;
        }
        long long y=0;
        long long x=0;
        // debug(one,zero);

        if(one>1)
        {
            x=binpow(2,one);
            x--;
            x-=one;
        }
        if(zero>1)
        {
            y=binpow(2,zero);
            y--;
            y-=zero;
        }
        
        res=res+x+y;
    }
    res+=(n*m);
    cout<<res<<endl;
}