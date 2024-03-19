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
    long long n,c;
    cin>>n>>c;

    long long x=((c+1)*(c+2));
    x=x/2;
    // debug(x);
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    long long ce=0;
    long long co=0;
    for(long long i=0;i<n;i++)
    {
        if(a[i]%2==0)
        ce++;
        else
        co++;

        long long x1=(a[i]/2);
        x1++;
        // if(a[i]>0 && a[i]%2==0)
        // x1++;
        
        long long y1=(c-a[i]+1);
        // debug(i,x1,y1); 
        long long ans=(x1+y1);

        x-=ans;
    }
    x+=((ce*(ce+1))/2);
    x+=((co*(co+1))/2);
    cout<<x<<endl;
}