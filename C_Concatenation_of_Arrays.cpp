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
bool cmp(pair<long long,long long>&a,pair<long long,long long>&b)
{
    long long x1=max(a.first,a.second);
    long long x2=min(a.first,a.second);
    long long y1=max(b.first,b.second);
    long long y2=min(b.first,b.second);

    if(x1==y1)
    return x2<y2;

    return x1<y1;
}
void solve()
{
    long long n;
    cin>>n;

    vector<pair<long long,long long>>v;
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    sort(all(v),cmp);

    for(auto it:v)
    {
        cout<<it.first<<" "<<it.second<<" ";
    }
    cout<<endl;
}