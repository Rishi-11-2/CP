#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
bool compare(pair<long long,long long>a,pair<long long,long long>b)
{
    if(a.first==b.first)
    return a.second>b.second;

    return a.first<b.first;
}
void solve()
{
    long long n,p;
    cin>>n>>p;
    long long a[n],b[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }
    vector<pair<long long,long long>>v;
    for(long long i=0;i<n;i++)
    {
        v.push_back({b[i],a[i]});
    }
    sort(all(v),compare);
    // for(auto it:v)
    // {
    //     cout<<it.second<<" "<<it.first<<endl;
    // }
    long long curr=n;
    long long cost=p;
    curr--;
    for(long long i=0;i<n;i++)
    {
        if(v[i].first>p)
        break;
        long long cost4=(v[i].first*min(curr,v[i].second));
        cost+=cost4;
        curr=max(0LL,curr-v[i].second);
        if(curr==0)
        break;
    }
    cost=cost+(curr)*p;
    cout<<cost<<endl;
}