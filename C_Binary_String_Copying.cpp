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
    string s;
    cin >> s;
    int arr[n];
    int prefix[n + 1];
    for (int i = 0; i < n; i++)
    {
        arr[i] = (s[i] - '0');
    }
    prefix[1] = arr[0];
    prefix[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    // cout << "hi" << endl;
    int res = 1;
    // for (int i = 0; i <= n; i++)
    //     cout << prefix[i] << " ";
    // cout << endl;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        int r = y - x + 1;
        int a = r - (prefix[y] - prefix[x - 1]);
        cout << a << " " << r << endl;
        if (prefix[x + a] - prefix[x] != 0)
            res++;
    }
    // if (n == 1)
    // {
    //     cout << 1 << endl;
    //     return;
    // }
    cout << res << endl;
}