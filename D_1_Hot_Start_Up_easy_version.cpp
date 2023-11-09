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
    while(t--)
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
    vector<long long>hot;
    // vector<long long>cold;
    vector<long long>cold;
    hot.push_back(0);
    cold.push_back(0);
    for(long long i=0;i<k;i++)
    {
        long long x;
        cin>>x;
        cold.push_back(x);
    }
    for(long long i=0;i<k;i++)
    {
        long long x;
        cin>>x;
        hot.push_back(x);
    }
    // cout<<hot[2]<<endl;
    // vector<vector<vector<long long>>>dp(n+1,vector<)
    map<vector<long long>,long long>mp;
    function<long long(long long,long long,long long)>f=[&](long long i,long long prev1,long long prev2)->long long{
        if(i==n)
        return 0;
        if(mp.find({i,prev1,prev2})!=mp.end())
        return mp[{i,prev1,prev2}]; 
        long long x=cold[a[i]];
        long long y=x+min(f(i+1,a[i],prev2),f(i+1,prev1,a[i]));
        long long res=y;
        if(a[i]==prev1)
        {
            res=min(res,hot[a[i]]+f(i+1,a[i],prev2));
        }
        if(a[i]==prev2)
        {
            res=min(res,hot[a[i]]+f(i+1,prev1,a[i]));
        }
        return  mp[{i,prev1,prev2}]=res;
    };
    long long x=f(0,0,0);
    cout<<x<<endl;
}