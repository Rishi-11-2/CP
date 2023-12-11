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
    long long n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    long long plain=m;
    long long logo=0;
    long long res=0;
    for(long long i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            logo=0;
            plain=m;
        }
        if(s[i]=='1')
        {
            if(plain>0)
            plain--;
            else
            logo--;
        }
        if(s[i]=='2')
        logo--;

       res=max(res,abs(logo));
    }
    cout<<res<<endl;
}