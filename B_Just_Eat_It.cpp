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
    long long n;
    cin>>n;
    long long arr[n];
    long long flag=1;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<=0)
        flag=0;
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        return;
    }
    long long sum=0;
    long long res=0;
    long long ts=0;
    long long idx=0;
    int flag1=0;
    for(long long i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<=0)
        {
            sum=0;
            flag1=1;
        }
        ts+=arr[i];
        if(!flag1 && i==n-1)
        continue;
        res=max(res,sum);
    }
    // debug(res,ts);
    if(res>=ts)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}