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
void solve()
{
    long long n;
    cin>>n;
    long long l=0;
    long long r=(long long)(2e9);
    long long res=r;
    while(r>=l)
    {
        long long m=(l+r)>>1;
        long long x=m*(m-1)/2+m;
        // cout<<x<<endl;
        if(x<n)
        {
            res=m;
            l=m+1;
        }
        else if(x>n)
        {
            r=m-1;
        }
        else if(x==n)
        {
            res=m;
            break;
        }
    }   
    // cout<<res<<endl;
    r=res;
    long long y1=n-(r*(r-1)/2);
    long long y2=n-((r+1)*(r)/2);
    if((r+1)*r/2<=n)
    {
        cout<<min(r+y1,r+1+y2)<<endl;
    }
    else
    {
        cout<<r+y1<<endl;
    }

}