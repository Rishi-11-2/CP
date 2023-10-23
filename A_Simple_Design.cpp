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
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=(i%10);
        i/=10;
    }
    return s;
}
void solve()
{
    int x,k;
    cin>>x>>k;
    int i=x;
    while(true)
    {
        if(sum(i)%k==0)
        {
            cout<<i<<endl;
            return;
        }
        i++;
    }
}