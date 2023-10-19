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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long res = 0;
    reverse(arr, arr + n);
    int low = 0;
    int high = n - 1;
    high = high - k * 2;
    long long s = 0;
    for (int i = low; i <= high; i++)
    {
        s += arr[i];
    }
    while (high < n)
    {
        // cout << s << endl;
        res = max(res, s);
        s = s - arr[low] * 1LL;
        s = s + arr[high + 1];
        s = s + arr[high + 2];
        low = low + 1;
        high = high + 2;
    }
    cout << res << endl;
}