// https://codeforces.com/contest/1550/problem/B
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
    int n, a, b;
    cin >> n >> a >> b;
    string z;
    cin >> z;
    int s = (n * a);
    if (b > 0)
    {
        s += (n * b);
        cout << s << el;
        return;
    }
    else
    {
        int g_o = 0;
        int g_z = 0;
        int x = z[0] - '0';
        for (int i = 1; i < n; i++)
        {
            int y = z[i] - '0';
            if (x != y)
            {
                if (x == 1)
                    g_o++;
                else
                    g_z++;
            }
            x = y;
        }
        if (x == 1)
            g_o++;
        else
            g_z++;
        x = min(g_o, g_z);

        s += ((x + 1) * b);
        cout << s << el;
        return;
    }
}