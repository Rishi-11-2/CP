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
    int x1, y;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int a[3];
    int b[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i] >> b[i];
    sort(a, a + 3);
    sort(b, b + 3);
    int cx = 0;
    int cy = 0;
    for (int i = 0; i < 2; i++)
    {
        if (a[i] == a[i + 1])
            cx = 1;
    }
    for (int i = 0; i < 2; i++)
    {
        if (b[i] == b[i + 1])
            cy = 1;
    }
    if (cx == 1 && cy == 1)
        cout << "NO" << el;
    else
        cout << "YES" << el;
}