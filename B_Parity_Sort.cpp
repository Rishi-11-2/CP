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
    int vis[n];
    memset(vis, 0, sizeof(vis));
    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2)
        {
            vis[i] = 1;
            odd.push_back(arr[i]);
        }
        else
        {
            vis[i] = 2;
            even.push_back(arr[i]);
        }
    }
    sort(all(even));
    sort(all(odd));
    reverse(all(odd));
    reverse(all(even));
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 1)
        {
            arr[i] = odd.back();
            odd.pop_back();
        }
        else if (vis[i] == 2)
        {
            arr[i] = even.back();
            even.pop_back();
        }
    }
    if (is_sorted(arr, arr + n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}