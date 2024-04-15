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

bool cmp(pair<long long,long long>&a,pair<long long,long long>&b)
{
    if(a.first==b.first)
    return a.second<b.second;

    return a.first<b.first;
}
void solve()
{
    long long n,m,k;
    cin>>n>>m>>k;

    vector<pair<long long,long long>>v;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    for(long long i=0;i<n;i++)
    {
        v.push_back({arr[i],i});
    }

    map<long long,long long>mp;
    sort(all(v));

    long long kk=k;
    for(auto it:v)
    {
        mp[it.second]=min(m,kk);
        // debug(it.first,it.second,mp[it.second]);
        kk-=min(m,kk);
        if(kk==0)
        break;
    }

    long long cost=0;
    long long extra=0;
    for(long long i=0;i<n;i++)
    {
        cost+=((arr[i]+extra)*mp[i]);
        extra+=mp[i];
    }
    cout<<cost<<endl;
}