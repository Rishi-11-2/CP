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
    long long n,l,r;
    cin>>n>>l>>r;

    long long arr[n];

    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    multiset<long long,greater<long long>>ss;
    l--;
    r--;
    for(long long i=l;i<=r;i++)
    {
        ss.insert(arr[i]);
    }
    multiset<long long>left;
    multiset<long long>right;

    for(long long i=0;i<l;i++)
    {
        left.insert(arr[i]);
    }

    for(long long i=r+1;i<n;i++)
    {
        right.insert(arr[i]);
    }

    auto sss=ss;
    long long sum1=0;
    while(!left.empty() && !ss.empty())
    {
        auto a=*left.begin();
        auto b=*ss.begin();

        if(a>=b)
        break;
        left.erase(left.begin());
        ss.erase(ss.begin());
        // debug(a);
        sum1+=a;
    }
    while(!ss.empty())
    {
        sum1+=*ss.begin();
        ss.erase(ss.begin());
    }
    long long sum2=0;
    while(!right.empty() && !sss.empty())
    {
        auto a=*right.begin();
        auto b=*sss.begin();

        if(a>=b)
        break;
        right.erase(right.begin());
        sss.erase(sss.begin());
        // debug(a);
        sum2+=a;
    }
    while(!sss.empty())
    {
        sum2+=*sss.begin();
        sss.erase(sss.begin());
    }
    cout<<min(sum1,sum2)<<endl;

}