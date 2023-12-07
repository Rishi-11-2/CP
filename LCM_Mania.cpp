#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool isPowerOfTwo(long long n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
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
void solve()
{
    long long n;
    cin>>n;
    if(n==1||isPowerOfTwo(n))
    {
        cout<<-1<<endl;
        return;
    }
    if(n%3==0)
    {
        cout<<(n/3)<<" "<<(n/3)<<" "<<(n/3)<<endl;
    }
    else if(n%2==0)
    {
        long long x=2;
        while(x<=n)
        {
            long long y=n-x;
            long long z=y/2;
            long long lcm=(x*z)/__gcd(x,z);
            // cout<<lcm<<" "<<x<<endl;
            if(lcm==z)
            {
                cout<<1<<" "<<x<<" "<<z<<endl;
                return;
            }
            x=(x*(2*1LL));
        }
    }
    else
    {
        cout<<1<<" "<<1<<" "<<(n/2)<<endl;
    }
}