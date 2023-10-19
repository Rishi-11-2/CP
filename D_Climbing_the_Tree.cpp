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
    int q;
    cin >> q;
    set<int> s;
    vector<int> res;
    int flag = 0;
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int a, b, n;
            cin >> a >> b >> n;
            if (flag == 0)
            {
                s.insert((a - b) * (n - 1) + a);
            }
        }
    }
}