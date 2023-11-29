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
    long long n,m,k;
    cin>>n>>m>>k;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    map<pair<long long,long long>,long long>mp;
    for(long long i=0;i<k;i++)
    {
        long long x,y,c;
        cin>>x>>y>>c;
        mp[{x,y}]=c;
    }
    vector<vector<long long>>dp((1<<(n+1)),vector<long long>(n+1,-1));
    function<long long(long long ,long long)>f=[&](long long mask,long long prev)->long long
    {
        // cout<<mask<<endl;
        if(__builtin_popcount(mask)==m)
        {
            // cout<<"hi"<<endl;
            return 0;
        }
        if(dp[mask][prev]!=-1)
        return dp[mask][prev];
        long long res=0;
        for(long long i=1;i<=n;i++)
        {
            if((mask&(1<<i))!=0)
            continue;
            long long newMask=mask|(1<<i);
            res=max(res,f(newMask,i)+a[i-1]+mp[{prev,i}]);
        }
        // cout<<mask<<" "<<prev<<endl;
        return dp[mask][prev]=res;
    };
    long long x=f(0,0);
    cout<<x<<endl;
}