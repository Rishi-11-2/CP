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
    string x = "codeforces";
    int c = 0;
    for (int i = 0; i < 10; i++)
    {
        if (x[i] != s[i])
            c++;
    }
    cout << c << endl;
}