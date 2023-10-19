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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int prefix[n];
    int suffix[n];
    for (int i = 0; i < n; i++)
    {
        prefix[i] = i + arr[i];
        suffix[i] = arr[i] - i;
    }
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], prefix[i]);
        suffix[n - i - 1] = max(suffix[n - i], suffix[n - i - 1]);
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        res = max(res, arr[i] + prefix[i - 1] + suffix[i + 1]);
    }
    cout << res << endl;
}