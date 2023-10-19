#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
void solve()
{
    long long n;
    cin >> n;
    long long arr[n];
    long long count = 0LL;
    long long s = 0LL;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    long long minm = *min_element(arr, arr + n);
    long long maxm = *max_element(arr, arr + n);
    if (maxm - minm <= 1)
    {
        cout << 0 << endl;
        return;
    }
    long long x = s / n;
    // count += s % n;
    // cout << x << endl;
    for (int i = 0; i < n; i++)
    {
        count += abs(x - arr[i]) * 1LL;
    }
    long long y = count / (2 * 1LL);
    // if (s % n == n - 1)
    //     count--;
    cout << max(y, s / n) << endl;
}