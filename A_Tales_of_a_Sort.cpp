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
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b[i] = arr[i];
    }
    if (is_sorted(arr, arr + n))
    {
        cout << 0 << endl;
        return;
    }
    int idx = -1;
    sort(b, b + n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != b[i])
        {
            idx = i;
            break;
        }
    }
    int maxm = 0;
    for (int i = 0; i <= idx; i++)
    {
        maxm = max(maxm, arr[i]);
    }
    cout << maxm << endl;
}