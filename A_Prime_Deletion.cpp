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
bool isPrime(string z)
{
    int x = stoi(z);
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string z;
            z.append(1, s[i]);
            z.append(1, s[j]);
            if (isPrime(z))
            {
                cout << z << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}