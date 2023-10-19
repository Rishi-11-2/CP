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
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, 0);
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = (i / k);
        // cout << x << endl;
        if (i % k)
            x++;
        if (c < x)
        {
            c++;
            v[i] = 1;
        }
    }
    int d = 0;
    for (int i = n; i >= 1; i--)
    {
        if (v[i] == 1)
            d++;
        int j = (n - (i - 1));
        int x = (j / k);
        if (j % k)
            x++;
        if (d < x)
        {
            d++;
            v[i] = 1;
        }
    }
    c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 1)
            c++;
    }
    cout << c << endl;
}