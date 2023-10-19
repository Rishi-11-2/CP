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
    int arr[n * m];
    for (int i = 0; i < (n * m); i++)
    {
        cin >> arr[i];
    }
    int t = n * m;
    long long res = 0;
    sort(arr, arr + t);
    res = (arr[t - 1] - arr[0]) * (t - min(n, m));
    long long s1 = 0;
    long long s2 = 0;
    long long s = 0;
    s1 = (arr[t - 1] - arr[1]);
    s2 = (arr[t - 2] - arr[0]);
    // cout << s1 << " " << s2 << endl;
    s = max(s1, s2);
    res = res + s * (1LL * (min(n, m) - 1));
    cout << res << endl;
}