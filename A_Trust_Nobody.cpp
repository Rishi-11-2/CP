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
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
    }
    // vector<int> v(n + 1, 0);
    // v[0] = 0;
    // v[n] = 1;
    int res = 0;
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == n)
            res++;
        if (arr[i] == 0)
            ct++;
    }
    if (res == n)
    {
        cout << -1 << endl;
        return;
    }
    if (ct == n)
    {
        cout << 0 << endl;
        return;
    }
    // if (res == 0)
    // {
    //     cout << n << endl;
    //     return;
    // }
    // cout << res << endl;
    m[n] = 0;
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] != 0 && arr[i] > res)
        {
            if (m[arr[i]] > arr[i])
            {
                cout << n << endl;
                return;
            }
            res += m[arr[i]];
            m[arr[i]] = 0;
        }
    }
    cout << res << endl;
}