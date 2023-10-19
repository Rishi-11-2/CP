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
    int x = n * (n + 1);
    x /= 2;
    if (n != 1 && x % n == 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && (i % 4 == 0 || i % 2 == 0))
            swap(v[i], v[i + 1]);
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}