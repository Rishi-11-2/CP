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
    vector<long long>v(n,0);
    for(long long i=0;i<n;i++)
    cin>>v[i];
    
    long long low=0;
    long long high=(long long)(1e12);
    long long res=low;

    function<long long(long long)>f=[&](long long mid)->long long{
        auto vv=v;
        for(long long i=n-1;i>=2;i--)
        {
            long long x=vv[i]-mid;
            if(x<0)
            return 0;
            long long d=min(v[i],x)/3;
            vv[i]-=(3*d);
            vv[i-1]+=d;
            vv[i-2]+=2*d;
            // for(auto it:vv)
            // {
            //     cout<<it<<" ";
            // }
            // cout<<endl;
        }
        long long minm=*min_element(all(vv));
        if(minm>=mid)
        return 1;
        
        return 0;
    };
    // cout<<f(15)<<endl;
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(f(mid))
        {
            // debug(mid);
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<res<<endl;
}