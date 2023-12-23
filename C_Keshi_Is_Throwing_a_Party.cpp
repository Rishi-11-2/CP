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
    long long a[n];
    long long b[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    long long low=0;
    long long high=n;
    long long res=low;
    function<long long(long long)>f=[&](long long mid)->long long{
        /* we are chosing mid people and now suppose we start from the poorest*/
        /* we will always take the poorest. Now we try to take that person that is second ,
        only richer than the first poorest*/
        long long res=0;
        int count=0;
        for(long long i=0;i<n;i++)
        {
            // debug(mid-i,a[i],b[i],count);
            if((a[i]>=(mid-(count+1))) && (b[i]>=count))
            {
                count++;
                res++;
            }
        }

        return (res>=mid);

    };
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(f(mid))
        {
            // debug(mid);
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<res<<endl;
}