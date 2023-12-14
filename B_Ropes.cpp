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
    // cin >> t;
        solve();
}
void solve()
{
    int n,k;
    cin>>n>>k;

    long double arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    // cout<<"hi"<<endl;
    long double low=0.00000001;
    long double high=(1e12);
    long double res=0;
    function<int(long double)>f=[&](long double mid)->int{

        long long s=0;
        for(int i=0;i<n;i++)
        {
            long long x=((arr[i])/mid);
            s+=x;
            if(s>=k)
            return 1;
        }
        if(s>=k)
        return 1;
        return 0;
    };
    while(high-low>=(0.00000001))
    {
        long double mid=(low+high)/(2);
            // debug(mid);
        if(f(mid))
        {
            res=max(mid,res);
            low=mid+0.00000001;
        }
        else
        {
            high=mid-0.00000001;
        }
    }
    cout<<setprecision(10)<<fixed<<res<<endl;
}