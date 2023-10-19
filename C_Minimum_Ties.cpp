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
    int x = n * (n - 1);
    x /= 2;
    int k = 0;
    for (int i = x; i >= 1; i--)
    {
        if (i % n == 0)
        {
            k = i;
            break;
        }
    }
    // cout << x << endl;
    int y = x / n;
    int t = x - k;
    int ta = t;
    for (int i = 1; i < n; i++)
    {
        int count = 0;
        int flag = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (t > 0 && (j == (i + ta)))
            {
                t--;
                flag = 0;
                cout << 0 << " ";
            }
            else if (count < y)
            {
                count++;
                cout << 1 << " ";
            }
            else
                cout << -1 << " ";
        }
    }
    cout << endl;
}