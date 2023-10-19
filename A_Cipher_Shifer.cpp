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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string z = "";
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        i++;
        z += c;
        while (s[i] != c)
        {
            i++;
        }
    }
    cout << z << endl;
}