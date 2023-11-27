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
    int n;
    cin>>n;
    string s;
    cin>>s;
    /*
      0-red
      1-yellow
      2-green
    */
    int r=0;
    int y=0;
    int g=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='R')
        {
            r=1+max(r,y);
        }
        else if(s[i-1]=='Y')
        {
            y=1+max(y,g);
        }
        else if(s[i-1]=='G')
        {
            g=1+max(g,r);
        }
    }

    int xx=max({r,y,g});

    cout<<xx<<endl;
}