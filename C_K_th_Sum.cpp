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
    long long n,k;
    cin>>n>>k;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    long long b[n];
    for(long long i=0;i<n;i++)
    cin>>b[i];

    sort(a,a+n);
    sort(b,b+n);
    long long low=a[0]+b[0];
    long long high=a[n-1]+b[n-1];

    function<long long(long long)>f=[&](long long mid)->long long{
        long long count=0;
        for(long long i=0;i<n;i++)
        {
            if(b[i]>mid)
            break;
            
            long long x=mid-b[i];

            auto it=upper_bound(a,a+n,x)-a;
            // debug(it);
            count+=it;
        }
        return (count>=k);
    };
    // f(9);
    long long res=low;
    // debug(low,high);
    while(low<=high)
    {
        long long mid=(low+high)/(2LL);
        // debug(mid);
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<res<<endl;
}