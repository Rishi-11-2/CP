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
long long check(long long arr[], long long n, double x, double c)
{
    double sum = c;
    for (int i = 0; i < n; i++)
    {
        double t = arr[i] + x + x;
        sum = sum - (t * t);
    }
    return sum;
}
void solve()
{
    long double n, c;
    cin >> n >> c;
    long double arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long double low = 0LL;
    long double high = (long double)(1e8);
    while (low <= high)
    {
        double mid = (long long)low + (high - low) / 2;
        // cout << mid << endl;
        // cout << check(arr, n, mid, c) << endl;
        if (check(arr, n, mid, c) == 0)
        {
            cout << mid << endl;
            return;
        }
        else if (check(arr, n, mid, c) < 0)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
}