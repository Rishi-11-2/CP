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
long long LCM(long long a,long long b)
{

    long long g=__gcd(a,b);

    return (a*b)/g;
}
void solve()
{
    long long n;
    cin>>n;

    long long arr[n];
    set<long long>s;
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    long long lc=1;
    long long maxm=*max_element(arr,arr+n);
    for(long long i=0;i<n;i++)
    {
        lc=LCM(lc,arr[i]);
        if(lc>maxm)
        {
            cout<<n<<endl;
            return;
        }
        s.insert(arr[i]);
    }
    map<long long,long long>dp;

    dp[1]=0;

    for(long long i=0;i<n;i++)
    {
        auto ndp=dp;
        for(auto it:dp)
        {
            long long new_lcm=LCM(it.first,arr[i]);
            // debug(new_lcm);
            if(ndp.find(new_lcm)==ndp.end())
            ndp[new_lcm]=1+it.second;
            else
            {
                ndp[new_lcm]=max(ndp[new_lcm],it.second+1);
            }
        }
        dp=ndp;
    }
    maxm=0;
    for(auto it:dp)
    {
        if(s.find(it.first)==s.end())
        maxm=max(maxm,it.second);
    }

    cout<<maxm<<endl;
}