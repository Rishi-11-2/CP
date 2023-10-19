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
    int n, k;
    cin >> n >> k;
    int arr[n];
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == k)
            flag = 1;
    }
    sort(arr, arr + n);
    if (arr[0] == k && arr[n - 1] == k)
    {
        cout << 0 << endl;
        return;
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += (k - arr[i]);
    }
    if (s == 0 || flag == 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}