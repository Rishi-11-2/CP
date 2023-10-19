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
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int count = 0;
    int a = 2;
    int b = 1;
    int res = 0;
    int z = x;
    for (int i = 0; i < n; i++)
    {
        if (x > arr[i])
        {
            count++;
            int p = arr[i] / 2;
            x += p;
        }
        else
        {
            while (x <= arr[i] && a > 0)
            {
                x = x * 2;
                a--;
            }
            while (x <= arr[i] && b > 0)
            {
                x = x * 3;
                b--;
            }
            if (x <= arr[i] && a == 0 && b == 0)
                break;
            int h = arr[i] / 2;
            x = x + h;
            count++;
        }
    }

    res = max(res, count);
    count = 0;
    a = 2;
    b = 1;
    x = z;
    for (int i = 0; i < n; i++)
    {
        if (x > arr[i])
        {
            count++;
            int p = arr[i] / 2;
            x += p;
        }
        else
        {

            while ((x <= arr[i]) && (b > 0))
            {
                x = x * 3;
                b--;
            }
            while (x <= arr[i] && a > 0)
            {
                x = x * 2;
                a--;
            }
            if (x <= arr[i] && a == 0 && b == 0)
                break;
            int h = arr[i] / 2;
            x = x + h;
            count++;
        }
    }
    res = max(res, count);
    count = 0;
    a = 2;
    b = 1;
    x = z;
    for (int i = 0; i < n; i++)
    {
        if (x > arr[i])
        {
            count++;
            int p = arr[i] / 2;
            x += p;
        }
        else
        {
            while (x <= arr[i] && a > 1)
            {
                x = x * 2;
                a--;
            }

            while ((x <= arr[i]) && (b > 0))
            {
                x = x * 3;
                b--;
            }
            while (x <= arr[i] && a > 0)
            {
                x = x * 2;
                a--;
            }
            if (x <= arr[i] && a == 0 && b == 0)
                break;
            int h = arr[i] / 2;
            x = x + h;
            count++;
        }
    }
    res = max(res, count);
    cout << res << el;
}