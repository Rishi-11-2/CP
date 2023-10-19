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
int s;
double PI = acos(-1);
inline bool cmp(int x, int y)
{
    return ((x | s) > (y | s));
}
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
    int n;
    cin >> n;
    s = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int v = min((int)31, n);
    for (int i = 0; i < v; i++)
    {
        sort(arr + i, arr + n, cmp);
        s |= arr[i];
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << el;
}