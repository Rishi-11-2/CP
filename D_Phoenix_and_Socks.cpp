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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> left(n + 1, 0);
    vector<int> right(n + 1, 0);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i < l)
            left[arr[i]]++;
        else
            right[arr[i]]++;
    }
    int L = l;
    int R = r;
    for (int i = 1; i <= n; i++)
    {
        int minm = min(left[i], right[i]);
        left[i] -= minm;
        right[i] -= minm;
        L -= minm;
        R -= minm;
    }
    if (L < R)
    {
        swap(L, R);
        left.swap(right);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int extra = L - R;
        int canDo = left[i] / 2;
        int Do = min(canDo * 2, extra);
        res += Do / 2;
        L -= Do;
    }
    res += L;
    cout << res << endl;
}