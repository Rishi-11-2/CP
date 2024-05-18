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
    // long long t;
    // cin >> t;
        solve();

}
void solve()
{
    long long n,h,l,r;
    cin>>n>>h>>l>>r;

    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    vector<vector<long long>>dp(n+1,vector<long long>(h,-1));
    function<long long(long long,long long)>f=[&](long long i,long long h1)->long long{

        if(i==n)
        {
            return 0;
        }

        if(dp[i][h1]!=-1)
        return dp[i][h1];
        long long x1=arr[i]-1+h1;
        if(x1>=h)
        {
            x1-=h;
        }
        long long x2=arr[i]+h1;
        if(x2>=h)
        {
            x2-=h;
        }
        long long y1=f(i+1,x1);
        long long y2=f(i+1,x2);
        if(x1>=l && x1<=r)
        {
            y1++;
        }
        if(x2>=l && x2<=r)
        {
            y2++;
        }

        return dp[i][h1]= max(y1,y2);
    };
    long long x=f(0,0);

    cout<<x<<endl;
}