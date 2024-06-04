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
        solve();

}
void solve()
{
    tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update>s;

    long long n;
    cin>>n;
    vector<pair<long long,long long>>v;

    for(long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    long long res=0;
    sort(all(v));
    for(long long i=0;i<n;i++)
    {
        long long sz=(long long)(s.size());
        long long yy=s.order_of_key(v[i].first);
        long long a=sz-yy;
        res+=a;
        s.insert(v[i].second);
    }
    cout<<res<<endl;
}