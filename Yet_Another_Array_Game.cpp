#include <bits/stdc++.h>
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
void solve();
long long s;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    long long t;
    cin >> t>>s;
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
    sort(arr,arr+n);
    vector<long long>prefix(n,0);
    prefix[0]=arr[0];
    for(long long i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    long long terms=1;
    long long ans=0;
    long long x=0;
    for(long long i=n-1;i>=0;i-=2)
    {
        long long sum=prefix[i+terms-1];
        if(i>0)
        sum-=prefix[i-1];
        // debug(sum);
        ans=max(ans,sum);
        terms++;
        x=sum;

    }
    if(s)
    cout<<ans<<endl;
    else
    cout<<x<<endl;
}