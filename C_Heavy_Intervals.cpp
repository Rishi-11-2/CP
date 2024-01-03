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
    long long l[n];
    set<long long>s;
    for(long long i=0;i<n;i++)
    {
        cin>>l[i];
    }
    
    long long r[n];
    for(long long i=0;i<n;i++)
    {
        cin>>r[i];
        s.insert(r[i]);
    }
    long long c[n];
    for(long long i=0;i<n;i++)
    cin>>c[i];
     sort(l,l+n,greater<long long>());
    sort(c,c+n);
    vector<long long>v;
    for(long long i=0;i<n;i++)
    {
        auto it=s.upper_bound(l[i]);
        if(it==s.end())
        it--;
        // debug(*it);
        v.push_back(*it-l[i]);
        s.erase(it);
    }
    sort(all(v));
    long long res1=0;
    // long long res2=0;
    for(long long i=0;i<n;i++)
    {
        res1+=(v[i]*c[n-i-1]);
    }
    cout<<res1<<endl;
}