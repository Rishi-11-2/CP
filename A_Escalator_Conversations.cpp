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
    int n, m, k, H;
    cin >> n >> m >> k >> H;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x = abs(arr[i] - H);
        if (x % k == 0 && x <= (m - 1) * k && x > 0)
        {
            // cout << arr[i] << endl;
            res++;
        }
    }
    cout << res << endl;
}