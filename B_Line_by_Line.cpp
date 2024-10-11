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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve(int );
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(12);
    int t = 1;
    int count=1;
    cin >> t;
    while (t--)
    {
        solve(count++);
    }
}
void solve(int cas)
{
    int n,p;
    cin>>n>>p;

    long double pp= (p*1.0)/(100*1.0);

    long double x=1.0;
    for(int i=1;i<min(n,100);i++)
    {
        x=x*pp;
    }

    long double low=0;
    long double high=1;
    // debug(x);
    long double epsilon = 1e-14;
    long double res=0;
    function<int(long double)>f=[&](long double mid)->int{
        long double res=1.0;
        for(int i=1;i<=min(n,100);i++)
        {
            res=res*mid;
        }
        if((res-x)<epsilon)
        return 1;
        return 0;
    };
    while((high-low)>epsilon)
    {
        long double mid=(low+high)/2.0;

        if(f(mid))
        {
            res=mid;
            low=mid+epsilon;
        }
        else
        {
            high=mid-epsilon;
        }
    } 
    debug(res);
    long double hundred=100;
    res=res*hundred;
    res=res-p;
    cout<<"Case #"<<cas<<":"<<" ";
    cout<<res<<endl;  
}