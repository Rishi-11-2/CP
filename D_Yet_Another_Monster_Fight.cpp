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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    priority_queue<pair<int,int>>left,right;
    for(int i=1;i<n;i++)
    {
        right.push({a[i],i});
    }

    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(!left.empty() && !right.empty())
        {
            int l=max(a[i]+i,a[i]+abs(i-left.top().second));
            int r=max(a[i]+(n-i-1),a[i]+abs(i-right.top().second));
            res=min({l,r,res});
        }
    }
    cout<<res<<endl;
}