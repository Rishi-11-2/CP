#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
long long dp[100001][2][2];
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
long long r(int i, int a, int b, int p, int n)
{
    if (i == n)
        return 0;
    if (dp[i][a][b] != -1)
        return dp[i][a][b];
    if (p == 0)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    int x = r(0, 0, 0, 0, a.length());
    cout << x << endl;
}