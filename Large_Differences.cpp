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
    long long n,k;
    cin>>n>>k;

    long long a[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long s=0;
    for(long long i=1;i<n;i++)
    {
        s+=abs(a[i]-a[i-1]);
    }
    long long res=s;
    for(long long i=0;i<n;i++)
    {
        long long d1=0;
        long long d2=0;
        long long new_d11=0;
        long long new_d12=0;
        long long new_d21=0;
        long long new_d22=0;
        if(i>0)
        {
            d1=abs(a[i]-a[i-1]);
            new_d11=abs(a[i-1]-k);
            new_d12=abs(a[i-1]-1);

        }
        if(i<n-1)
        {
            d2=abs(a[i]-a[i+1]);
            new_d21=abs(a[i+1]-k);
            new_d22=abs(a[i+1]-1);

        }

        res=max(res,s-d1-d2+max(new_d11+new_d21,new_d12+new_d22));
    }
    cout<<res<<endl;
}