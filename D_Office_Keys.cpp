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
    long long n,k,p;
    cin>>n>>k>>p;
    vector<long long>a(n);
    for(long long i=0;i<n;i++)
    cin>>a[i];
    vector<long long>b(k);
    for(long long i=0;i<k;i++)
    {
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b));

     vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long j)->long long{
        if(i<0)
        return 0;
        if(j<0)
        return (int)(1e18);
        if(dp[i][j]!=-1)
        return dp[i][j];
        long long x1=f(i-1,j-1);
        long long x3=abs(a[i]-b[j])+abs(p-b[j]);
        long long x2=f(i,j-1);
        return dp[i][j]=min(max(x1,x3),x2);
    };
    cout<<f(n-1,k-1)<<endl;
}