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
bool compare(pair<long long,long long>&a,pair<long long,long long>&b)
{
    if(a.first==b.first)
    return a.second<b.second;

    return a.first<b.first;
}
void solve()
{
    long long n;
    cin>>n;

    tree < long long,null_type, greater<long long> ,rb_tree_tag, tree_order_statistics_node_update  > s;
    vector<pair<long long,long long>>v;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(all(v),compare);
    long long count=0;
    s.insert(v[0].second);
    for(long long i=1;i<n;i++)
    {
        long long x=s.order_of_key(v[i].second);
        count +=x;
        s.insert(v[i].second);
    }
    // for(auto it:s)
    // cout<<it<<" ";
    // cout<<endl;
    cout<<count<<endl;
}