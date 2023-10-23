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
    long long x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    long long res=(x2-x1)*(y2-y1)+1;
    cout<<res<<endl;
}