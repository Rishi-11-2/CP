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
    int n,k,x;
    cin>>n>>k>>x;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    function<int(int,int)>f=[&](int i,int k1)->int{
        if(k1<0)
        return -0x3f3f3f3f;
        if(i==n)
        {
            if(k1==0)
            return 0;
            else
            return -0x3f3f3f3f; 
        }
        int x1=a[i]-x+f(i+1,k1);
        int x2=a[i]+x+f(i+1,k1-1);
        int res=max(x1,x2);
        return res;
    };
    int yy=f(0,k);
    cout<<yy<<endl;
}