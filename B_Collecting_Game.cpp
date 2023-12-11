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
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    long long count=0;
    long long sum=0;
    map<long long,long long>mp;
    set<long long>s;
    map<long long,long long>xx;
    for(long long i=0;i<n;i++)
    {
        s.insert(arr[i]);
        xx[arr[i]]++;
    }
    vector<long long>x(all(s));
    for(auto it:s)
    {
        mp[it]=sum+xx[it]*it;
        sum=mp[it];
    }
    map<long long,long long>ans;
     sum=0;
     sum=mp[x[0]];
     count=xx[x[0]];
    long long i=1;
    long long j=0;
    long long m=(long long)(x.size());
    // cout<<m<<endl;
    while(i<=m)
    {
        // long long flag=0;
        while(i<m && sum>=x[i])
        {
            sum+=(xx[x[i]]*x[i]*1LL);
            // flag=1;
            count+=xx[x[i]];
            i++;
        }
        // cout<<count<<" "<<j<<" "<<sum<<" "<<i<<endl;
        ans[x[j]]=count;
        if(xx[x[j]]>=1)
        ans[x[j]]--;
        j++;
        if(j==i)
        {
            sum+=xx[x[i]]*x[i];
            count+=xx[x[i]];    
            i++;
        }
    }
    // cout<<count<<endl;
    // while(j<m)
    // {
    //     ans[x[j]]=count-1;
    //     j++;
    // }
    for(long long i=0;i<n;i++)
    {
        cout<<ans[arr[i]]<<" ";
    }
    cout<<endl;
}