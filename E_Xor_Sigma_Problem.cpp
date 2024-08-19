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
    // cin >> t;
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
    cin>>arr[i];
    
        long long sum = 0;
 
    long long s = 1;
 
    for (long long i = 0; i < 30; i++) {
 
        long long count_odd = 0;
 
        bool odd = 0;
        for (long long j = 0; j < n; j++) {
            if ((arr[j] & (1LL << i)) > 0)
                odd = (!odd);
            if (odd)
                count_odd++;
        }
        
        for (long long j = 0; j < n; j++) {
            sum += (s * count_odd);
 
            if ((arr[j] & (1LL << i)) > 0)
                count_odd = (((n-1)-(j+1)+1)- (count_odd-1));
        }
 
        s *= 2LL;
    }
 
    // returning the sum
    
    for(long long i=0;i<n;i++)
    {
        sum-=arr[i];
    }

    cout<<sum<<endl;


}