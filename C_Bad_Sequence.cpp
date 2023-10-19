
#include <bits/stdc++.h>
using namespace std;
#define el endl

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
    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << k << el;
        return;
    }
    int y = (n * (n + 1)) / 2;
    y--;
    int a = k - y;
    if (a < 1)
    {
        cout << -1 << el;
        return;
    }
    int arr[n];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = 1;
    }
    arr[n - 1] = a;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << el;
}