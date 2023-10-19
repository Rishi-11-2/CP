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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>v;
    int maxm=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        maxm=max(maxm,a);
    }
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int a=v[i].first;
        int b=v[i].second;
        if(a>=x)
        {
            res=min(res,1);
        }
        else if(b>=a)
        continue;

        int z=a-b;
        int rem=max(0,x-maxm);
        int count=rem/z;
        if(rem%z)
        count++;
        res=min(res,1+count);
    }
    if(res==INT_MAX)
    res=-1;
    cout<<res<<endl;
}