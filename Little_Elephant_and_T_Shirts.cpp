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
    cin.ignore();
    vector<vector<long long>>v(n+1,vector<long long>(101,0));
    for(long long i=1;i<=n;i++)
    {
        string s;
        getline(cin,s);
        stringstream in(s);
        long long a;
        while(in>>a)
        {
            // cout<<a<<endl;
            v[i][a]=1;
        }
    }
    // we can iterate over t-shirts
    long long m=(1<<(n+1));
    m--;
    const long long mod=(long long)(1e9+7);
    vector<vector<long long>>dp(102,vector<long long>(m+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long mask)->long long{
        if(i==101)
        {
            // cout<<mask<<endl;
            if(mask==m)
             return 1;
            return 0;
        }
        if(dp[i][mask]!=-1)
        return dp[i][mask];
        long long res=f(i+1,mask)%mod;
        for(long long j=1;j<=n;j++)
        {
            if((mask & (1<<j))>0)
            continue;
            if(v[j][i]==0)
            continue;            
            long long newMask=mask|(1<<j);
            res=(res%mod+f(i+1,newMask)%mod)%mod;
        }
        return dp[i][mask]=res%mod;
    };
    long long x=f(1,1)%mod;
    cout<<x<<endl;
}