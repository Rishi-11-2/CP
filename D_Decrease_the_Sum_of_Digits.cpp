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
    long long n, s;
    cin >> n >> s;
    string z = "";
    long long k = n;
    while (k > 0)
    {
        z += (k % 10 + '0');
        k /= 10;
    }
    reverse(all(z));
    cout << z << endl;
    int x = 0;
    int idx = -1;
    for (int i = 0; i < z.length(); i++)
    {
        int y = z[i] - '0';
        if (x + y > s)
        {
            idx = z.length() - i - 1;
            break;
        }
    }
}