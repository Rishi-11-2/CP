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
    long long s=0;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    if(n==1)
    {
        cout<<max(0LL,arr[0]-k)<<endl;
        return;
    }
    long long low=0;
    long long high=(long long)(1e18);
    long long res=low;
    sort(all(arr));
    vector<long long>suffix(n+1,0);
    suffix[n]=0LL;
    suffix[n-1]=arr[n-1];
    for(long long i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]+arr[i];
    }
    function<long long(long long)>f=[&](long long mid)->long long{
        long long sum=s;
        auto a=arr;
        if(sum<=k)
        {
            return 1;
        }
        // long long count=0;
        long long xxx=mid;
        if(mid>=n)
        {
            sum-=a[0];
            a[0]-=(mid-(n-1));
            sum+=a[0];
            mid=n-1;
        }
        // debug(sum);
        for(long long i=1;i<=mid;i++)
        {
            long long xx=sum-(i-1)+(mid-i+1)*(a[0]-(i-1))-suffix[(n)-(mid-i+1)];
            // debug(xx,xxx,i,a[0],sum,suffix[n-(mid-i)]);
            if(xx<=k)
            return 1;
        }
        long long count=(sum-k);
        if(count<=mid)
        return 1;
        return 0;
    };
    // cout<<f(7)<<endl;
    while(low<=high)
    {
        long long mid=(low+high)/2;
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