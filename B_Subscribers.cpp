#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
void solve()
{
    long long n;
    cin >> n;
    string s = to_string(n);
    if (n <= (1000 - 1))
    {
        cout << n << endl;
    }
    else
    {
        string z = "";
        int x = s.length();
        x -= 3;
        for (int i = 1; i <= x; i++)
        {
            z += '0';
        }
        for (int i = s.length() - (x + 1); i >= 0; i--)
        {
            z += s[i];
        }
        reverse(z.begin(), z.end());
        cout << z << endl;
    }
}