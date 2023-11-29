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
    long long n;
    cin>>n;
    long long a[n];
    set<long long>s;
    map<long long,long long>mp;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
        mp[a[i]]++;
    }
    vector<long long>v(all(s));

    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    function<long long(long long,long long)>f=[&](long long l,long long r)->long long{
        if(l>r)
        return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        long long res=0;
        long long x=mp[v[r]]*(v[r]-v[l])+f(l,r-1);
        long long y=mp[v[l]]*(v[r]-v[l])+f(l+1,r);

        res=min(x,y);

        return dp[l][r]=res;
    };
    long long sz=(long long)(v.size());
    long long x=f(0,sz-1);

    cout<<x<<endl;
}