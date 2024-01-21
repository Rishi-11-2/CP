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
    long long n;
    cin>>n;
    if(n%2)
    {
        cout<<0<<endl;
        return;
    }
    long long x=10;
    long long res=0;
    int count=0;
    // debug("jo");
    // debug("jo");
    for(int i=n;i>=2;i-=2)
    {
    // debug("jo");
        // cout<<i<<" ";
        int y=i;
        while((y%10)==0)
        {
            y=y/10;
            count++;
        }

    }
    // cout<<count<<endl;
    // cout<<endl;
    while(x<=n)
    {
        // long long y=x;
        debug(x,n/x);
        res+=(n/x);
        if(x==n)
        break;
        x=x*10;

    }
    cout<<res<<endl;
}