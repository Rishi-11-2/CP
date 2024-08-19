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
    long long n,k;
    cin>>n>>k;

    vector<pair<long long,long long>>v;
    long long maxm=0;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        v.push_back({arr[i],arr[i]+k-1});
        maxm=max(maxm,arr[i]+k-1);
    }
    for(long long i=0;i<n;i++)
    {
        long long d=(maxm-v[i].first)/(2LL*k);
        v[i].first+=(2LL)*k*d;
        v[i].second+=(2LL)*k*d;
    }


    long long l=v[0].first;
    long long r=v[0].second;
    for(long long i=1;i<n;i++)
    {
        if(v[i].second<l || v[i].first>r)
        {
            cout<<-1<<endl;
            return;
        }
        l=max(l,v[i].first);
        r=min(r,v[i].second);
    }
    cout<<l<<endl;
}