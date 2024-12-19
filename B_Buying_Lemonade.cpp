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
void solve()
{
    long long n,k;
    cin>>n>>k;

    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];

    long long ans=0;
    sort(arr,arr+n);
    long long i=0;
    long long sum=0;
    long long rem=0;
    while(i<n && k>0)
    {
        // debug(ans,i);
        if(((n-i)*(arr[i]-rem))<=k)
        {
            ans+=(n-i)*(arr[i]-rem);
            k-=(n-i)*(arr[i]-rem);
            rem+=(arr[i]-rem);
            k=max(0LL,k);
            // debug(k);
            if(k==0)
            break;
            long long j=i;
            while(i<n && arr[i]==arr[j])
            {
                ans++;
                i++;
            }
        }
        else
        {
            // debug(i,ans);
            while(k>0)
            {
                ans+=min(arr[i]-rem,k);
                k-=(arr[i]-rem);
                k=max(0LL,k);
            }
        }
        // debug(ans,i);
    }
    // if(n==2)
    // ans--;
    cout<<ans<<endl;

}