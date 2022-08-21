// https://codeforces.com/contest/1720/problem/C
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
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int r_z = 0;
    int z = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '0')
            {
                r_z++;
            }
            if (s[i][j] == '1')
                z++;
            if (s[i][j] == '0')
            {
                if (i != 0 and s[i][j] == s[i - 1][j])
                    flag = true;
                if (i != n - 1 and s[i][j] == s[i + 1][j])
                    flag = true;
                if (j != 0 and s[i][j] == s[i][j - 1])
                    flag = true;
                if (j != m - 1 and s[i][j] == s[i][j + 1])
                    flag = true;

                if (i != 0 and j != 0 and s[i][j] == s[i - 1][j - 1])
                    flag = true;
                if (i != 0 and j != m - 1 and s[i][j] == s[i - 1][j + 1])
                    flag = true;
                if (i != n - 1 and j != 0 and s[i][j] == s[i + 1][j - 1])
                    flag = true;
                if (i != n - 1 and j != m - 1 and s[i][j] == s[i + 1][j + 1])
                    flag = true;
            }
        }
    }

    if (z == (n * m))
        cout << z - 2 << el;
    else if (r_z == (n * m))
        cout << 0 << el;
    else if (flag == true)
        cout << z << el;
    else
        cout << z - 1 << el;
}