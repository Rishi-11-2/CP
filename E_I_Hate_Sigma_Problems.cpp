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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{

    long long n;
    cin>>n;

    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    long long sum = n * (n + 1) / 2;
 
    long long res = 0;
 
    map<long long, vector<long long> > mp;
 
    for (long long i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }
 
    for (auto x : mp) {
 
        auto arr = x.second;
 
        arr.push_back(n);
 
        long long len = arr.size();
 
        long long ans = 0;
 
        long long prev = -1;
        for (long long j = 0; j < len; j++) {
            long long diff = arr[j] - prev - 1;
 
            ans += (diff*(diff + 1))/ 2;
            prev = arr[j];
        }
        res+=(sum - ans);
    }

    cout<<res<<endl;
 
}