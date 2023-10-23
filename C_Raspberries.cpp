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
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int count=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]%k==0)
        {
            cout<<0<<endl;
            return;
        }
        int y=a[i]/k;
        int z=k*(y+1);
        count=min(count,z-a[i]);
    }
    int fcount=INT_MAX;
    if(k==4)
    {
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0)
            {
                v.push_back(0);
                continue;
            }
            int y=a[i]/2;
            int z=2*(y+1);
            v.push_back(z-a[i]);
        }
        sort(all(v));
        fcount=v[0]+v[1];
    }
    cout<<min(count,fcount)<<endl;
}