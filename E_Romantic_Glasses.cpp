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
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    vector<long long>odd(n+1,0);
    vector<long long>even(n+1,0);
    unordered_set<long long>e;
    unordered_set<long long>o;
    set<long long>s;
    // e.insert(0);
    // o.insert(0);
    // unordered_set<long long>o;
    for(long long i=1;i<=n;i++)
    {
        odd[i]=odd[i-1];
        even[i]=even[i-1];
        if(i%2)
        {
            odd[i]+=arr[i-1];
        }
        else
        {
            even[i]+=arr[i-1];
        }
        long long diff=odd[i]-even[i];
        if(s.find(diff)!=s.end())
        {
            cout<<"YES"<<endl;
            return;
        }
        s.insert(odd[i]-even[i]);
    }

    for(long long i=1;i<=n;i++)
    {
        if(odd[i]==even[i])
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;

}