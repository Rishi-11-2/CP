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
    int maxm = 2;
    if (n % 2 == 0 && n % 3 == 0)
    {
        for (int i = 4; i < n; i++)
        {
            if (n % i != 0)
            {
                maxm = i;
                break;
            }
        }
    }
    else if (n % 2 == 0)
        maxm = 3;
    else if (n % 3 == 0)
        maxm = 2;
    int x = 0;
    vector<char> v(n, '/');
    for (int i = 0; i < n; i++)
    {
        v[i] = (char)('a' + x);
        x = (x + 1) % (maxm);
    }
    for (auto it : v)
    {
        cout << it;
    }
    cout << endl;
}