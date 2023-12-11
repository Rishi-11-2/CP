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
    cin>>arr[i];
    vector<long long>prefix(n,0);
    prefix[0]=arr[0];
    for(long long i=1;i<n;i++)
    {
        prefix[i]=arr[i]+prefix[i-1];
    }
    function<long long(long long,long long)>f=[&](long long mid,long long target)->long long{
        long long s=prefix[mid-1];
        if(s>=target)
        return 1;
        return 0;
    };
    function<long long(long long)>fans=[&](long long x)->long long{
        long long low=1;
        long long high=n;
        long long res=n;
        while(low<=high)
        {
            long long mid=(low+high)/2;

            if(f(mid,x))
            {
                // debug(mid,x);
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    };
    long long m;
    cin>>m;
    long long b[m];
    for(long long i=0;i<m;i++)
    {
        cin>>b[i];

        long long ans=fans(b[i]);
        cout<<ans<<endl;
    }
}