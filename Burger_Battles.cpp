#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define all(v) (v).begin(), (v).end()
#define int long long int
#define lld long double
bool isFeasible(int arr[], int n, int k, int ans)
{
    int req = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > ans)
        {
            req++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return (req <= k);
}
int minPages(int arr[], int n, int k)
{
    int sum = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }
    int low = mx;
    int high = sum;
    int res = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isFeasible(arr, n, k, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
void solve();
int32_t main()
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
    int arr[n];
    int s1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s1 = max(s1, arr[i]);
    }
    int s = 0;
    for (int i = 1; i <= min(n, m); i++)
    {
        s += minPages(arr, n, i);
    }
    for (int i = n + 1; i <= m; i++)
        s += s1;
    cout << s << endl;
}