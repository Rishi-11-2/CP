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
    int arr[n][n];
    int c = 0;
    int l = 1;
    int r = (n * n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (c % 2 == 0)
                    arr[i][j] = l++;
                else
                    arr[i][j] = r--;
                c++;
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (c % 2 == 0)
                    arr[i][j] = l++;
                else
                    arr[i][j] = r--;
                c++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << " ";
            cout << el;
        }
    }
}