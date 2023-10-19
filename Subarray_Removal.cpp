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
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    long long ans[n + 1];
    for (long long i = 0; i < n; i++)
        ans[arr[i]] = i;

    long long low = n + 1;
    long long high = 0;
    long long res = 0;
    for (long long i = n; i >= 2; i--)
    {
        low = min(low, ans[i]);
        high = max(high, ans[i]);
        // cout<<low<<" "<<high<<endl;
        if (high - low + 1 == n - i + 1)
            res = n - i + 1;
    }
    cout << res << endl;
}