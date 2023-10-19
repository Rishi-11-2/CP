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
    double px,py;
    cin>>px>>py;
    double ax,ay;
    cin>>ax>>ay;
    double bx,by;
    cin>>bx>>by;
    double oa=sqrtl((0-ax)*(0-ax)+(0-ay)*(0-ay));
    double ob=sqrtl((0-bx)*(0-bx)+(0-by)*(0-by));
    double pa=sqrtl((ax-px)*(ax-px)+(ay-py)*(ay-py));
    double pb=sqrtl((bx-px)*(bx-px)+(by-py)*(by-py));
    double ab=sqrtl((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    double res=1e9;
    res=min(res,max(oa,pa));
    res=min(res,max(ob,pb));
    res=min(res,max({oa,pb,ab/(2.0)}));
    res=min(res,max({ob,pa,ab/(2.0)}));
    cout<<res<<endl;
}