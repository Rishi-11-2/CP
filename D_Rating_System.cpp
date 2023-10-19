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
        cin >> arr[i];
    long long sum = 0, mx = 0, ans = 0, diff = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mx = max(mx, sum);
        if ((sum - mx) < diff)
        {
            diff = sum - mx;
            ans = mx;
        }
    }
    cout << ans << endl;
    // After 21 attempts solved it and that too by looking at the tutorial
    // wow. I dont have any mind
}