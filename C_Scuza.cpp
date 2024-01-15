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
    long long n,q;
    cin>>n>>q;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    long long k[q];
    vector<pair<long long,long long>>v;
    for(long long i=0;i<q;i++)
    {
        cin>>k[i];
        v.push_back({k[i],i});
    }
    sort(all(v));
    long long i=0;
    long long j=0;
    long long s=0;
    vector<long long>ans(q,0);
    while(j<q)
    {
        while(i<n && v[j].first>=a[i])
        {
            s+=a[i];
            i++;
        }
        ans[v[j].second]=s;
        j++;
    }

    for(auto it:ans)
    cout<<it<<" ";
    cout<<endl;
}