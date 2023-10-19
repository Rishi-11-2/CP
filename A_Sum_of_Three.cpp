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
    // cout<<n<<endl;
    if(n<=6)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(n%3==0)
    {
        int a=1;
        int b=4;
        int c=n-(a+b);
        if(c!=a && c!=b && c>0)
        {
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    if(n%3!=0)
    {
        int a=1;
        int b=2;
        int c=n-(a+b);
        if(c!=a && c!=b && c>0)
        {
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}