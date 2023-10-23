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
    int n,m,d;
    cin>>n>>m>>d;
    int a[m];
    vector<int>v;
    v.push_back(1-d);
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    v.push_back(n+1);
    int sum=0;
    for(int i=1;i<(int)(v.size());i++)
    {
        sum+=(v[i]-v[i-1]-1)/d+1;
        // sum--;
    }
    sum--;
    // cout<<sum<<endl;
    vector<int>res;
    int x=sum;
    for(int i=1;i<=m;i++)
    {
        int right=(v[i+1]-v[i]-1)/d;
        int left=(v[i]-v[i-1]-1)/d;
        int z=(v[i+1]-v[i-1]-1)/d;
        int y=sum-(left+right+1)+z;
        // cout<<y<<" "<<z<<" "<<left<<" "<<right<<endl;
        if(y<x)
        {
            res.clear();
            x=y;
        }
        if(y==x)
        {
            res.push_back(i);
        }
    }
    cout<<x<<" "<<res.size()<<endl;
}