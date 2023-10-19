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
long long bC(long long x,long long *b,long long n)
{
    long long res=INT_MAX;
    long long c=-1;
    for(long long i=0;i<n;i++)
    {
        long long xx=abs(b[i]-x);
        if(xx<res)
        {
            res=xx;
            c=i;
        }
    }
    return c;
}
void solve()
{
    long long n;
    cin>>n;
    long long a[n];
    long long b[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }
    vector<long long>v1={0,n-1,bC(a[0],b,n)};
    vector<long long>v2={0,n-1,bC(a[n-1],b,n)};
    long long minm=INT_MAX;
    for(auto i:v1)
    {
        for(auto j:v2)
        {
            long long res=abs(a[0]-b[i])+abs(a[n-1]-b[j]);
            if(i>0  && j>0)
            {
                long long y=bC(b[0],a,n);
                res+=abs(a[y]-b[0]);
            }
            if(i<n-1 && j<n-1)
            {
                long long y=bC(b[n-1],a,n);
                res+=abs(a[y]-b[n-1]);
            }
            minm=min(minm,res);
        }
    }
    cout<<minm<<endl;
}