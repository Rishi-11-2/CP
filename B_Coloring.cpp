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
    int n, m, k;
    cin >> n >> m >> k;
    int arr[m];
    int maxC = 0;
    int f = 0;
    int y = (n + k - 1) / k;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        if (arr[i] == y)
            f++;
        if (arr[i] > y)
            f = INT_MAX;
    }
    int z = ((n - 1) % k) + 1;
    if (f > z)
        cout << "NO" << el;
    else
        cout << "YES" << el;
}