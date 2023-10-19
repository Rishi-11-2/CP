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
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    map<pair<long long, long long>, long long> grid;
    for (int i = 1; i <= m; i++)
    {
        long long x, y;
        cin >> x >> y;
        grid[{x, y}] = 1;
    }
    long long a[] = {-1, 1, 0, 0};
    long long b[] = {0, 0, 1, -1};
    map<char, long long> x;
    x['L'] = 0;
    x['R'] = 1;
    x['U'] = 2;
    x['D'] = 3;
    long long g = h;
    long long s1 = 0;
    long long s2 = 0;
    for (int i = 0; i < n; i++)
    {
        long long f = x[s[i]];
        // cout << f << endl;
        long long y = s1 + a[f];
        long long z = s2 + b[f];
        s1 = y;
        s2 = z;
        h = h - 1;
        if (h < 0)
        {
            cout << "No" << endl;
            return;
        }
        if ((h < k && (grid[{y, z}] == 1)))
        {
            h = max(h, k);
        }
    }
    if (h < 0)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}