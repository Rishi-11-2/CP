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
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int c = 0;
    int b[n];
    int min1 = INT_MAX;
    b[0] = -1;
    b[n - 1] = -1;
    int k = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (k == arr[i])
            c++;
    }
    int t = 0;
    if (n % 2 == 0)
    {
        t += n / 2 - 1;
    }
    else
        t = n / 2;
    if (c == n)
    {
        cout << t << el;
        return;
    }
    c = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (b[i] < b[i - 1] or b[i] < b[i + 1])
        {
            b[i] = max(arr[i - 1], arr[i + 1]) - arr[i] + 1;
        }
        else
        {
            b[i] = 0;
            c++;
        }
    }

    if (c == t)
    {
        cout << 0 << el;
        return;
    }
    if (c == 0)
    {
        sort(b, b + n);
        int s = 0;
        for (int i = 0; i < c; i++)
            s += b[i];
        cout << s << el;
    }
    for (int i = 2; i < n - 1; i++)
    {
        if (b[i] == 0)
            min1 = min(min1, (b[i - 1] + b[i]));
    }
    int min2 = INT_MAX;
    for (int i = 1; i < n - 1; i++)
    {
        if (b[i - 1] != 0 and b[i + 1] != 0 and b[i] != 0)
            min2 = min(min2, b[i]);
    }
    cout << min(min2, min1) << el;
}