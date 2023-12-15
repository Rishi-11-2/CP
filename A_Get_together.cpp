#include <bits/stdc++.h>
using namespace std;
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
    srand(time(NULL));
        solve();
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<long double,long double>>v;
    for(int i=0;i<n;i++)
    {
        long double x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    long double error=0.00000001;
    long double low=0;
    long double high=1e18;
    long double res=1e10;
    function<int(long double)>f=[&](long double mid)->int{
        // vector<pair<long double,long double>>vv;
        long double l=-1e18;
        long double r=1e18;
        for(int i=0;i<n;i++)
        {
            long double x=v[i].first-(mid*v[i].second);
            long double y=v[i].first+(mid*v[i].second);
            l=max(l,x);
            r=min(r,y);
            // vv.push_back({x,y});
        }
        if(l>r)
        return 0;
        return 1;
    };
    int count=0;
    while(high-low>=error)
    {
       long double mid=(low+high)/(2*1.0);
       if(f(mid))
       {
         res=mid;
         high=mid-error;
       }
       else
       {
        low=mid+error;
       }
       if(count>100)
       break;
       count++;
    }
    cout<<res<<endl;
}