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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
long long pow2(long long x)
{
    long long count=0;
    long long y=1LL;
    while(y<x)
    {
        count++;
        y=y*(2*1LL);
    }
    return count;
}
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];
    long long s=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    vector<long long>b(n,0);

    for(long long i=0;i<n;i++)
    {
        long long x=pow2(arr[i]);
        long long y=x-1;
        if(y<0)
        y=0;
        long long diff1=abs(arr[i]-(1<<x));
        long long diff2=abs(arr[i]-(1<<y));
        if(diff1<diff2 && (1<<x)<=(int)(1e9))
        {
            b[i]=(1<<x);
        }
        else
        {
            b[i]=(1<<y);
        }

    }
    for(auto it:b)
    cout<<it<<" ";
    cout<<endl;
}