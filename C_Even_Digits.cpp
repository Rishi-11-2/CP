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
    long long count=1;
    long long n;
    cin>>n;
    long long arr[6]={-1,0,2,4,6,8};
    if(n<=5)
    {
        cout<<arr[n]<<endl;
        return;
    }

    n-=5;
    count=2;
    long long product=20;
    while(n-product>0)
    {
        n-=product;
        product*=5;
        count++;
    }
    string res;
    long long flag=0;
        long long x=binpow(5,count-1);
    while(count>0)
    {
        // debug(n,x);
        long long y=1;
        if(n>=x)
        {
             y=(n+x-1)/x;
            n=n%x;
            if(n==0)
            n=(x);
        }
        // debug(y);
        if(flag==0)
        {
            // product/=4;
            y++;
            flag=1;
        }
        x/=5;
        // if(n==0)
        // y=4;
        res+=to_string(arr[y]);
        count--;
    }
    cout<<res<<endl;
}