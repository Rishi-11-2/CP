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

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    vector<long long>v;
    for(long long i=1;i<=n-2;i++)
    {
        // cout<<5<<" ";
        v.push_back(5);
    }
    // cout<<2;
    v.push_back(7);
    v.push_back(2);

    // cout<<endl;
    // int prev1=v[0];
    // int prev2=v[0];
    // for(int i=1;i<n;i++)
    // {
    //     prev1=prev1&v[i];
    //     prev2=prev2^v[i];
    //     cout<<prev1<<" "<<prev2<<endl;
    // }

    // prev1=v[n-1];
    // prev2=v[n-1];
    // for(int i=n-2;i>=0;i--)
    // {
    //     prev1=prev1&v[i];
    //     prev2=prev2^v[i];
    //     cout<<prev1<<" "<<prev2<<endl;
    // }

    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}