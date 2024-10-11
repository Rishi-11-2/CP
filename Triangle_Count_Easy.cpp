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
    long long n;
    cin>>n;

    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    vector<pair<long long,long long>>v;

    for(long long i=1;i<n;i++)
    {
        // when x is not the largest
        // when arr[i] is the largest
        v.push_back({arr[i]-arr[i-1]+1,arr[i]});

        // when x is the largest
        // when arr[i] is the second largest

        v.push_back({arr[i],arr[i]+arr[i-1]-1});
    }

    sort(all(v));

    vector<pair<long long,long long>>res;
    if((int)v.size()>=1)
    res.push_back(v[0]);
    long long j=0;
    for(long long i=1;i<(long long)v.size();i++)
    {
        if(v[i].first<=res[j].second)
        {
            res[j].second=max(res[j].second,v[i].second);
        }
        else
        {
            j++;
            res.push_back(v[i]);
        }
    }

    long long ans=0;

    for(auto it:res)
    {
        // debug(it.first,it.second);
        ans+=(it.second-it.first+1);
    }
    cout<<ans<<endl;
}