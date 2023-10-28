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
    long long n,k;
    cin>>n>>k;
    // const long long mod=(long long)(1e9)+7;
    vector<long long>dp(k+1,0);
    /*calculating the number of derangments that is the number of ways the no elements is at its required place
    dp relation is just like fibonacci except here we multiply with (i-1) at every step*/
    dp[1]=0;
    dp[2]=1;
    for(long long i=3;i<=k;i++)
    {
        dp[i]=((i-1)*(dp[i-1]+dp[i-2]));
    }
    vector<vector<long long>>c(n+1,vector<long long>(k+1,0));
    /*calculating the binomial coefficients using the recurrence
      nCk=n-1Ck-1 + n-1Ck */
    for(long long i=0;i<=n;i++)
    {
        for(long long j=0;j<=min(i,k);j++)
        {
            if(j==0||j==i)
            {
                c[i][j]=1;
                continue;
            }
            c[i][j]=(c[i-1][j-1]+c[i-1][j]);
        }
    }
    long long res=0;
    for(long long i=0;i<=k;i++)
    {
        res=(res+(c[n][i]*dp[i]));
    }
    cout<<(res+1LL)<<endl;
}