#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// long long getRandomNumber(long long l, long long r) {return uniform_long long_distribution<long long>(l, r)(rng);}
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
    long long count=0;
    long long limit=(2LL*n);
    // limit;
    for(long long i=1;i*i<=limit;i++)
    {
        long long x=(i*i)*1LL;
        long long y=x-1LL;
        if(y%2==0)
        {
            long long c=(y/(2*1LL));
            if(c>=1)
            count++;
        }
    }
    cout<<count<<endl;
}