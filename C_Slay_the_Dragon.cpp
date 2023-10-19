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
    solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    sort(arr, arr + n);
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = arr[i] + prefix[i - 1];
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        int s = 0;
        cin >> x >> y;
        int z = lower_bound(arr, arr + n, x) - arr;
        if (z == n)
        {
            s += (x - arr[z - 1]);
            s += max((y - (prefix[n - 1] - arr[n - 1])), 0LL);
        }
        else if (z == 0)
        {
            s += max((y - (prefix[n - 1] - arr[0])), 0LL);
        }
        else
        {
            // cout << z << el;
            int a = max(x - arr[z - 1], 0LL) + max((y - (prefix[n - 1] - arr[z - 1])), 0LL);
            int b = max(x - arr[z], 0LL) + max((y - (prefix[n - 1] - arr[z])), 0LL);
            // cout << a << " " << b << el;
            s = min(a, b);
        }
        cout << s << el;
    }
}