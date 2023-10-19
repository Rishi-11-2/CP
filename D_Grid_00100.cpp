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
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        if (k > 0)
        {
            v[i][i] = 1;
            k--;
        }
    }
    int r = 0;
    int c = 1;
    while (k > 0)
    {
        while (v[r][c] == 1)
        {
            r = (r + 1) % n;
        }
        v[r][c] = 1;
        k--;
        r = (r + 1) % n;
        c = (c + 1) % n;
    }
    int maxR = 0;
    int minR = INT_MAX;
    int maxC = 0;
    int minC = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += v[i][j];
        }
        maxR = max(maxR, s);
        minR = min(s, minR);
    }
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += v[j][i];
        }
        maxC = max(maxC, s);
        minC = min(minC, s);
    }
    // cout << maxC << " " << minC << " " << maxR << " " << minR << endl;
    if (minC == INT_MAX)
        minC = 0;
    if (minR == INT_MAX)
        minR = 0;
    int xx = maxC - minC;
    int yy = maxR - minR;
    cout << ((xx * xx) + (yy * yy)) << endl;
    for (auto &it : v)
    {
        for (auto &i : it)
            cout << i;
        cout << endl;
    }
}