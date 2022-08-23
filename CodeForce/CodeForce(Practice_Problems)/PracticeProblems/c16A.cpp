#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
#define INF INT_MAX
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n, m;
    cin >> n >> m;
    char c[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (c[i][j] != c[i][0])
            {
                cout << "NO" << el;
                return;
            }
        }
        if (i != 0 and c[i - 1][0] == c[i][0])
        {
            cout << "NO" << el;
            return;
        }
        if (i != n - 1 and c[i + 1][0] == c[i][0])
        {
            cout << "NO" << el;
            return;
        }
    }
    cout << "YES" << el;
    return;
}