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
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<vector<int>> v;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> a;
        a.push_back(x);
        a.push_back(y);
        a.push_back(z);
        v.push_back(a);
    }
    // cout << "hi" << endl;
    for (int i = 0; i < m; i++)
    {
        double a1 = v[i][1] * 1.0 - 1.0 * sqrt(1.0 * 4.0 * v[i][0] * v[i][2]);
        double a2 = v[i][1] * 1.0 + 1.0 * sqrt(1.0 * 4.0 * v[i][0] * v[i][2]);
        double minM = min(a1, a2);
        auto it = upper_bound(arr.begin(), arr.end(), (double)(minM)) - arr.begin();
        // cout << it << endl;
        if (it == n)
            it--;
        if (arr[it] > a1 && arr[it] < a2)
        {
            cout << "YES" << endl;
            cout << arr[it] << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        // cout << endl;
    }
    cout << endl;
}