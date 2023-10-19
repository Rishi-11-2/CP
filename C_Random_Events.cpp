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
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (is_sorted(arr, arr + n))
    {
        cout << 1.0 << endl;
        return;
    }
    int idx = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == i + 1)
            continue;
        idx = i + 1;
        break;
    }
    double res = 0.0;
    double curr1 = 1.0;
    double curr2 = 1.0;
    if (idx == -1)
    {
        cout << 1.0 << endl;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        double y;
        cin >> x >> y;
        if (x != 1 && x < idx)
        {
            curr1 = curr1 * y;
            curr2 = curr2 * (1 - y);
        }
        if (x >= idx)
        {
            // cout << "hi " << y * curr1 << " " << y * curr2 << endl;
            if (curr1 != curr2)
                res += (y * curr1) + ((y)*curr2);
            else
                res += (y * curr1);
            curr2 = curr2 * (1 - y);
            curr1 = curr1 * (1 - y);
        }
        // cout << curr1 << " " << curr2 << endl;
    }
    cout << res << endl;
}