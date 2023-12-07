#include <bits/stdc++.h>
using namespace std;
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
long long digsum(long long n)
{
    long long s=0;
    while(n>0)
    {
        s+=(n%(10*1LL));
        n/=(10*1LL);
    }
    return s;
}
void solve()
{
    long long n;
    cin>>n;
    long long count=1;

    while(n>0)
    {
        long long r=n%10;
        n/=10;
        long long c=0;
        for(long long i=0;i<=9;i++)
        {
            for(long long j=0;j<=9;j++)
            {
                if(r-(i+j)>=0)
                c++;
            }
        }
        if(c>0)
        count=count*(c*1LL);

    }
    cout<<count<<endl;
}