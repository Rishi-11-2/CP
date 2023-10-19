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
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int minm = INT_MAX;
    int pre[n];
    int suff[n];
    pre[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1];
        if (arr[i] - arr[i - 1] > k)
            pre[i] += 1;
    }
    suff[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1];
        if (arr[i + 1] - arr[i] > k)
            suff[i] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        minm = min(minm, pre[i] + suff[i]);
    }
    cout << minm << endl;
}