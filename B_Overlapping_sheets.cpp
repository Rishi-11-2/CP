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

    solve();
}
void solve()
{
    int n;
    cin >> n;
    set<vector<int>> s;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; i++)
        {
            for (int j = c; j < d; j++)
            {
                s.insert({i, j, i + 1, j + 1});
            }
        }
    }
    cout << (int)(s.size()) << endl;
}