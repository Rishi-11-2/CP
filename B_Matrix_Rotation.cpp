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
#define int long long int
#define lld long double
#define INF INT_MAX
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (auto &x : v)
        out << x << ' ';
    return out;
}
double PI = acos(-1);
void solve();
int32_t main()
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
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int a[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cin >> a[i][j];
    }
    int x1 = 1;
    int y1 = 1;
    int x2 = 1;
    int y2 = 1;
    if ((a[0][0] < a[0][1]))
        x1 = 1;
    else
        x1 = -1;
    if (a[1][0] < a[1][1])
        x2 = 1;
    else
        x2 = -1;
    if ((a[0][0] < a[1][0]))
        y1 = 1;
    else
        y1 = -1;
    if ((a[0][1] < a[1][1]))
        y2 = 1;
    else
        y2 = -1;
    if (x1 * x2 == -1)
        cout << "NO" << el;
    else if (y1 * y2 == -1)
        cout << "NO" << el;
    else
        cout << "YES" << el;
}