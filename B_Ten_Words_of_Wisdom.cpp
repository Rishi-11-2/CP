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
    int maxm = 0;
    int idx = -1;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x <= 10)
        {
            if (y > maxm)
            {
                idx = i;
                maxm = y;
            }
        }
    }
    cout << idx << endl;
}