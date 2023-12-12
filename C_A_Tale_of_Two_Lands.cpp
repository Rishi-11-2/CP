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
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]=abs(arr[i]);
    }
    
    sort(arr,arr+n);
    long long count=0;
    for(long long i=0;i<n;i++)
    {
        auto it=upper_bound(arr+i+1,arr+n,2*arr[i])-arr;
        long long r=it-(i+1);
        // debug(arr[i],r);
        count+=r;
    }
    cout<<count<<endl;
}