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
    // i hpe it
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> diff;
    for (int i = 1; i < n; i++)
    {
        int x = abs(arr[i] - arr[i - 1]);
        diff.push_back(x);
    }
    sort(all(diff));
    int s = 0;
    for (int i = 0; i < (n - k); i++)
    {
        s += diff[i];
    }
    cout << s << endl;
}