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
    auto isCheck = [&](int mid)
    {
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= mid || (arr[i] >= n - mid + 1))
                continue;
            if (arr[i] < prev)
                return false;
            prev = arr[i];
        }
        return true;
    };
    int low = 0;
    int high = n / 2;
    int res = n / 2;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (isCheck(mid))
        {
            high = mid;
            // cout << mid << endl;
            res = mid;
        }
        else
            low = mid + 1;
    }
    cout << res << endl;
}