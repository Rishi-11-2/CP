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
        solve();
}
long long count(long long d)
{
    long long c=0;
    while(d>0)
    {
        c+=(d%10);
        d/=10;
    }
    return c;
}
long long sqrt22(long long n)
{
    long long low=1;
    long long high=(long long)(1e9+100);
    long long res=high;
    while(low<=high)
    {
        long long mid=(low+high)/2LL;
        long long ss=mid*mid;
        if(ss==n)
        return mid;
        
        if(ss<n)
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return res;
}
void solve()
{
    long long n;
    cin>>n;
        long long z=(long long)1e12;
    for(long long i=1;i<=100;i++)
    {
        long long y=sqrt22(i*i+4LL*n);
        if(y*y!=(i*i+(4LL*n)))
        continue;
        long long x1=(-i+y)/2;
        long long x2=(-i-y)/2;
        long long y1=x1*x1+count(abs(x1))*x1-n;
        long long y2=x2*x2+count(abs(x2))*x2-n;
        if(y1==0)
        {
            if(x1>0)
            {
                // debug(y,x1,x2,i);
                z=min(z,x1);
            }
        }
        if(y2==0)
        {
            if(x2>0)
            {
                z=min(z,x2);
            }
        }

    }
    if(z==(long long)(1e12))
    cout<<-1<<endl;
    else
    cout<<z<<endl;
}