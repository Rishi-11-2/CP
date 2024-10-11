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
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
long long countSquares(long long a, long long b)
{
    return (floor(sqrtl(b)) - ceil(sqrtl(a)) + 1);
}
 
void solve()
{
    long long k;
    cin>>k;


    function<long long(long long)>f=[&](long long i)->long long{
        long long count=sqrtl(i);
        long long  ans=i-count;
        // debug(i,count,ans);
        if(ans>=k)
        return 1;
        return 0;
    };
    long long low=0;
    long long high=(long long)(2e18);
    long long res=-1;
    // cout<<f(11)<<endl;
    while(low<=high)
    {
        long long mid=(low+high)/2LL;

        if(f(mid))
        {
            // debug(mid);
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<(res)<<endl;



}