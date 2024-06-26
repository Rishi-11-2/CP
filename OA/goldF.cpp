#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b;
    cin >> b;

    int val[n];
    memset(val, 0, n);
    sort(a, a + n);
    int curr = 0;
    int s = b;
    for (int i = 0; i < n; i++)
    {
        if (s > a[i])
        {
            s -= a[i];
        }
        else
        {
            int x = a[i];
            while (x > s)
            {
                x /= 2;
                curr++;
            }
            s -= x;
            if (s == 0)
            {
                cout << curr << endl;
            }
            else
                cout << -1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}