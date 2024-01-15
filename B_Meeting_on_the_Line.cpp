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
    int n;
    cin>>n;
    vector<long long>x(n,0);
    for(long long i=0;i<n;i++)
    cin>>x[i];
    
    vector<long long>time(n,0);
    long double minm=1e9;
    for(long long i=0;i<n;i++)
    {
        cin>>time[i];
        minm=min(minm,(long double)time[i]);
    }
    long double error=1e-7;
    long double low=minm;
    long double high=1e9;
    long double res=low;
    // debug(minm);
    int flag=0;
     long double pos=0;
    function<long long(long double)>f=[&](long double mid)->long long{
        long double maxm=1e9;
        long double minm=0;
        for(long long i=0;i<n;i++)
        {
            maxm=min(maxm,(long double)x[i]+(mid-(long double)time[i]));
            minm=max(minm,(long double)x[i]-(mid-(long double)time[i]));
        }
        if(minm>maxm)
        return 0;
        if(flag)
        {
            pos=maxm;
        }
        return 1;
    };
    while(high-low>=error)
    {
        long double mid=(low+high)/(2.0);

        if(f(mid))
        {
            res=mid;
            high=mid-error;
        }
        else
        {
            low=mid+error;
        }
    }
    flag=1;
    long double z=f(res);
    cout<<pos<<endl;
}