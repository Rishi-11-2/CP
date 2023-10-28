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
    int count=0;
    while(!s.empty() && s[0]==s.back())
    {
        count++;
        s.pop_back();
    }
    if(s.empty())
    {
        if(count==2)
        {
            cout<<0<<endl;

        }
        else if(count==3)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<(count+2)/3<<endl;

        }
        return;
    }
    s.push_back('@');
    n=(int)(s.size());
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        count++;
        if(s[i]!=s[i+1])
        {
            ans+=(count/3);
            count=0;
        }
    }
    cout<<ans<<endl;
}