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
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    long long minm=*min_element(arr,arr+n);
    const long long mod=(long long)(1e9+7);
    long long count=0;
    for(long long i=0;i<n;i++)
    {
        if(arr[i]==minm)
        count++;
        if(arr[i]!=minm)
        {
            if((arr[i]&minm)!=minm)
            {
                cout<<0<<endl;
                return;
            }
        }
    }
    long long res=((count%mod)*(count-1)%mod)%mod;
    long long fact=1;
    for(long long i=1;i<=n-2;i++)
    {
        fact=((fact%mod)*(i%mod))%mod;
    }
    res=(res%mod*(fact)%mod)%mod;
    cout<<res<<endl;
}