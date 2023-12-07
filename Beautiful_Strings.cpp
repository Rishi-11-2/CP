#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
const long long mod=(long long)(1e9)+7;
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
    long long n;
    cin>>n;
    string s;
    cin>>s;

    set<char>ss;
    for(char c:s)
    {
        ss.insert(c);
    }

    long long sz=(long long)(ss.size());

    long long xx=n-sz;

    long long res=(n%mod*(n+1)%mod)%mod;

    xx=(xx%mod*4%mod)%mod;

    res=res-xx;
    res=(res/(2*1LL));
    cout<<res<<endl;
   
}