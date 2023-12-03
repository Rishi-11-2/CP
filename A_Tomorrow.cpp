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
    int M,D;
    cin>>M>>D;
    int y,m,d;
    cin>>y>>m>>d;
    if(d==D && m==M)
    {
        cout<<y+1<<" "<<1<<" "<<1<<endl;
    }
    else if(d==D)
    {
        cout<<y<<" "<<m+1<<" "<<1<<endl;
    }
    else
    {
        cout<<y<<" "<<m<<" "<<d+1<<endl;
    }
}