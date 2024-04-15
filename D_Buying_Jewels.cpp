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
    long long n,k;
    cin>>n>>k;

    if(n%k==0)
    {
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<(n/k)<<endl;
        return;
    }
    vector<long long>v;
    for(long long i=61;i>=0;i--)
    {
        if((n&(1LL<<i))!=0)
        {
            // cout<<(1LL<<i)<<endl;
            if(n>=(1LL<<i))
            v.push_back(1LL<<i);
        }
    }
    // for(auto it:v)   
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    long long sz=(long long)(v.size());
    // cout<<sz<<endl;
    if(sz<k||sz>60)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<sz<<endl;
    for(int i=0;i<min(60LL,sz);i++)
    {
        if(i<k)
        cout<<v[i]<<" ";
        else
        cout<<n<<" ";
    }
    cout<<endl;
}