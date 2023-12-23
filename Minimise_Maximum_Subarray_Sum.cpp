#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
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
    long long x,y;
    cin>>x>>y;
    if(y>=x)
    {
        cout<<1<<endl;
        return;
    }
    /*333334*/
    long long res=INT_MAX;
    long long low=1;
    long long high=(long long)(1e9);
    function<long long(long long)>f=[&](long long mid)->long long{

        long long groups=(x/mid);
        if(x%mid)
        groups++;
        if(groups-1<=y)
        return 1;
         
         return 0;
    };
    // cout<<f(333334)<<endl;
    while(low<=high)
    {
        long long mid=(low+high)/(2*1LL);
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    // cout<<res<<endl;
    cout<<max(res,x-2*y)<<endl;
}