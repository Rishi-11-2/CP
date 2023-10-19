#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l[k], r[k];
    for (int i = 0; i < k; i++)
        cin >> l[i];
    for (int i = 0; i < k; i++)
        cin >> r[i];
    int q;
    cin >> q;
    int query[q];
    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
    }
}