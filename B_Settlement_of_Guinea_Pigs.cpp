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
    int x = 0;
    int res = 0;
    int l_2 = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            x++;
        }
        else if ((arr[i] == 2))
        {
            y += x;
            x = 0;
        }
        int z = 0;
        if (y != 0)
        {
            z = y / 2 + 1;
        }
        res = max(res, z + x);
    }
    cout << res << endl;
}