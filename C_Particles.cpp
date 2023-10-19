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
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << arr[0] << endl;
        return;
    }
    long long res = INT_MIN;
    long long maxEnding = 0;
    long long s1 = 0;
    for (int i = 0; i < n; i += 2)
    {
        maxEnding = max(maxEnding, maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    maxEnding = 0;
    long long s2 = 0;
    for (int i = 1; i < n; i += 2)
    {
        maxEnding = max(maxEnding, maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    maxEnding = 0;

    long long s3 = 0;
    for (int i = n - 1; i >= 0; i -= 2)
    {
        maxEnding = max(maxEnding, maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    long long s4 = 0;
    maxEnding = 0;
    for (int i = n - 2; i >= 0; i -= 2)
    {
        maxEnding = max(maxEnding, maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    int flag = 0;
    long long x = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            flag = 1;
        }
        x = max(x, arr[i]);
    }
    if (!flag)
    {
        res = x;
    }
    cout << res << endl;
}