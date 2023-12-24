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
        solve();
}
void solve()
{
    long long n,k;
    cin>>n>>k;
    long long a[k];
    long long p=n;
    for(long long i=0;i<k;i++)
    {
        cin>>a[i];
        p--;
    }
    long long z=(2LL)*n-k;
    z=z/2;
    z-=p;
    // debug(z);
    function<long long(long long)>f=[&](long long mid)->long long{
        long long count=0;
        long long i=0;
        while(i<k-1)
        {
            if(a[i+1]-a[i]>mid)
            {
                i++;
            }
            else
            {
                count++;
                i+=2LL;
            }
        }
        if(count>=z)
        {
            return 1;
        }
        return 0;
    };
    long long high=n;
    long long low=0;
    long long res=high;
    long long sum=0;
    while(low<=high)
    {
        long long mid=(low+high)/(2LL);
        if(f(mid))
        {
            // sum=s;
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    int i=0;
    sum=0;
    while(i<k-1)
    {
        if(a[i+1]-a[i]>res)
        {
            i++;
        }
        else
        {
            // count++;
            sum+=a[i+1]-a[i];
            i+=2LL;
        }
    }
    cout<<sum<<endl;
}