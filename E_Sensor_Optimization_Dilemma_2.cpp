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
    long long n,x;
    cin>>n>>x;

    long long a[n],b[n],p[n],q[n];

    for(long long i=0;i<n;i++)
    {
        cin>>a[i]>>p[i]>>b[i]>>q[i];
    }

    function<long long(long long)>f=[&](long long mid)->long long{

        long long ans=x;

        for(long long i=0;i<n;i++)
        {
            long long minm=(long long)(1e18);
            for(long long j=0;j<=b[i];j++)
            {
                long long cost=j*p[i];
                long long rem=max(0LL,mid-(a[i]*j));

                cost+=((rem+b[i]-1)/b[i])*q[i];
                minm=min(minm,cost);
            }

            for(long long j=0;j<=a[i];j++)
            {
                long long cost=j*q[i];
                long long rem=max(0LL,mid-(b[i]*j));
                cost+=((rem+a[i]-1)/a[i])*p[i];
                minm=min(minm,cost);
            }
            ans-=minm;
            if(ans<0)
            return false;
        }
        return true;
    };
    long long low=0;

    long long high=(long long)(1e9);
    long long res=-1;
    while(low<=high)
    {
        long long mid=(low+high)/2LL;
        if(f(mid))
        {
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