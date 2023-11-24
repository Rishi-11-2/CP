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
    long long n,k;
    cin>>n>>k;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    long long hot[k];
    long long cold[k];
    for(long long i=0;i<k;i++)
    cin>>cold[i];
    for(long long i=0;i<k;i++)
    cin>>hot[i];
     vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long j)->long long{
        long long currIndex=1+max(i,j);
        if(currIndex==n)
        return 0;
        long long currProgramId=a[currIndex];
        long long res=0LL;
        if(dp[i+1][j+1]!=-1)
        return dp[i+1][j+1];
        if(i!=- 1 && currProgramId==a[i])
        {
            res=hot[currProgramId-1]+f(currIndex,j);
        }
        else if( j!=-1 && currProgramId==a[j])
        {
            res=hot[currProgramId-1]+f(i,currIndex);
        }
        else
        {
            res=cold[currProgramId-1]+min(f(i,currIndex),f(currIndex,j));
        }
        return dp[i+1][j+1]=res;
    };

    long long x= f(-1,-1);
    cout<<x<<endl;
}