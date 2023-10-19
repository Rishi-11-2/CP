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
#define int unsigned long long
#define lld long double
#define INF INT_MAX
#define ll unsigned long long
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
template <typename T, size_t N>
T mulmod(T (&multiplicands)[N], T m)
{
    T result = 1;
    for (T n : multiplicands)
        result = (result * (n % m)) % m;
    return result;
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
int mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {

        if (b % 2 == 1)
            res = (res + a) % mod;

        a = (a * 2) % mod;

        b /= 2;
    }
    return res % mod;
}
void solve()
{
    int mod = 1000000007;
    int n;
    cin >> n;
    int a = mulmod(mulmod(n * (n + 1), (2 * n) + 1, mod), 337 * 1LL, mod);
    int g = n * (n - 1);
    int b = mulmod(g, 1011 * 1LL, mod);
    int c = mulmod(mulmod((n - 1) * n, 2 * n - 1, mod), 337 * 1LL, mod);
    int s = 0;
    s = (a + b + c) % mod;
    cout << s << el;
}
