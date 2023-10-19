#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
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
    int minm = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        minm = min(minm, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == minm)
        {
            arr[i] = arr[i] + 1;
            break;
        }
    }
    int s = 1;
    for (int i = 0; i < n; i++)
    {
        s = s * arr[i];
    }
    cout << s << endl;
}