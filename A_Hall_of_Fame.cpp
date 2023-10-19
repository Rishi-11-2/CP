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
int mulmod(int a, int b, int mod)
{
    int res = 0; // Initialize result
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
    string s;
    cin >> s;
    int flagL = 0;
    int flagR = 0;
    int indexR = -1;
    int indexL = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            flagL = 1;

            indexL = i;
        }
        if (s[i] == 'R')
        {
            flagR = 1;

            indexR = i;
        }
    }

    if (flagL == 0 || flagR == 0)
    {
        cout << -1 << el;
        return;
    }
    // cout << flagR << el;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            cout << 0 << el;
            return;
        }
        if (s[i] == 'L' && s[i + 1] == 'R')
        {
            cout << i + 1 << el;
            return;
        }
    }
}