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
    long long n,k,x;
    cin>>n>>k>>x;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
     vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long k1)->long long{
        if(i==n)
        {
            return 0;
        }
        if(dp[i][k1]!=-1)
        return dp[i][k1];
        long long res=0;
        long long x1=0,x2=0;
        if(k1)
        {
            x1=max(0LL,a[i]+x+f(i+1,k1-1));
        }
        if(k1<n-i)// wiil have to ensure that exactly k operations are performed
        // else we will get wrong answer and that is what was happening
        // Therefore we ensures that k operations are only performed
        x2=max(0LL,a[i]-x+f(i+1,k1));
        res=max(x1,x2);
        return dp[i][k1]=res;
    };
    f(0,k);
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        res=max(res,*max_element(all(dp[i])));
    }
    cout<<res<<endl;
}