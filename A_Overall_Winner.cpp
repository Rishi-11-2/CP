#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    map<char, int> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        m[s[i]] += 1;
    }
    if (m['T'] > m['A'])
    {
        cout << 'T' << endl;
    }
    else if (m['A'] > m['T'])
    {
        cout << 'A' << endl;
    }
    else
    {
        if (s[n - 1] == 'A')
            cout << 'T' << endl;
        else
            cout << 'A' << endl;
    }
}