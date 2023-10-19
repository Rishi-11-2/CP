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
        cin >> arr[i];
    if (!is_sorted(arr, arr + n))
    {
        cout << 0 << endl;
        return;
    }
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        int x = arr[i] - arr[i - 1];
        int y = x / 2;
        y++;
        res = min(res, y);
    }
    cout << res << endl;
}