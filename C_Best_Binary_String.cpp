#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    char c = '0';
    string z = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            z += c;
        }
        else
        {
            z += s[i];
            c = s[i];
        }
    }
    cout << z << endl;
}