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
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        zero++;
        if(s[i]=='1')
        one++;
    }
    if(zero==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}