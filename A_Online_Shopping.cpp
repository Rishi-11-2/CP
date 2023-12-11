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
        solve();
}
void solve()
{
    long long n,s,k;
    cin>>n>>s>>k;
    long long p[n],q[n];
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        cin>>p[i]>>q[i];
        res+=(p[i]*q[i]);
    }
    if(res<s)
    {
        res+=k;
    }
    cout<<res<<endl;
}