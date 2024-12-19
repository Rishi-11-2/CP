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
    long long n;
    cin>>n;

    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    if(n%2==0)
    {
        long long maxm=0;
        for(long long i=0;(i+1)<n;i+=2)
        {
            maxm=max(maxm,arr[i+1]-arr[i]);
        }
        cout<<maxm<<endl;
        return;
    }

    function<long long(long long)>f=[&](long long mid)->long long{

        long long i=0;
        long long count=0;
        while(i<n)
        {
            long long diff=arr[i+1]-arr[i];
            if(diff<=mid)
            {
                i+=2;
            }
            else
            {
                count++;
                i++;
            }
        }
        if(count<=1)
        return 1;

        return 0;
    };
    long long low=0;
    long long high=(long long)(1e18);
    long long res=-1;
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