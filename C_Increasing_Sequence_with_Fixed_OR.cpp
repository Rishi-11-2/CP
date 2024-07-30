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
    
    long long idx=0;
    for(long long i=60;i>=0;i--)
    {
        if(n&(1LL<<i))
        {
            idx=i;
            break;
        }

    }
    vector<long long>v;
    v.push_back(n);
    for(long long j=0;j<idx;j++)
    {
        if(n&(1LL<<j))
        {
            long long k=j+1;
            long long m=(n & ~(1LL << (k - 1)));
            // debug(m,j);
            if(m>0)
            v.push_back(m);
        }
    }
    // debug(idx);
    long long k=idx+1;
    long long m=(n & ~(1LL << (k - 1)));
    if(m>0)
    v.push_back(m);

    reverse(all(v));
    long long sz=(long long)v.size();
    cout<<sz<<endl;
    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}