#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
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
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    long long a[k];
    long long t[k];
    for (long long i = 0; i < k; i++)
        cin >> a[i];
    for (long long i = 0; i < k; i++)
        cin >> t[i];

    long long arr[n];
    // memset does not work for INT_MAX;
    // memset only works for 0 or 1
    for (long long i = 0; i < n; i++)
        arr[i] = INT_MAX;
    for (long long i = 0; i < k; i++)
    {
        arr[a[i] - 1] = t[i];
    }
    long long p = INT_MAX;
    long long l[n];
    long long r[n];
    // for (long long i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    for (long long i = 0; i < n; i++)
    {
        p = min(p + 1, arr[i]);
        l[i] = p;
    }
    p = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        p = min(p + 1, arr[i]);
        r[i] = p;
    }
    for (int i = 0; i < n; i++)
    {
        cout << min(l[i], r[i]) << " ";
    }
    cout << endl;
}