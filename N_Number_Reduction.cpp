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
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    string z="";
    for (int i = 0; i < n; i++)
    {
        char x=s[i];
        if(x=='0')
        {
            while(z.size()>1 && x<z.back() && k>0)
            {
                z.pop_back();
                k--;
            }
        }
        else
        {
            while(!z.empty() && x<z.back() && k>0)
            {
                z.pop_back();
                k--;
            }
        }
        if(x!='0' && z.back()=='0')
        {
            if(z.size()<=k && z[0]>x)
            {
                k-=(int)(z.size());
                while(!z.empty())
                {
                    z.pop_back();
                }

            }
        }
        z+=x;
    }
    while(!z.empty() && k>0)
    {
        k--;
        z.pop_back();
    }
    cout<<z<<endl;
}