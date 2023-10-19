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
    int n, k;
    cin >> n >> k;
    if (k > n * 10)
    {
        cout << 0 << endl;
        return;
    }
    int a = 0;
    int b = 1;
    int c = a + b;
    for (int i = 3; i <= k; i++)
    {
        a = b;
        b = c;
        c = a + b;
    }
    int x = a;
    int y = b;
    // cout << x << " " << y << endl;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int t = n - (x * i);
        if (t % y == 0 && (t / y) >= (i))
        {
            // cout << x * i << " " << t << " " << y << endl;
            count++;
        }
    }
    cout << count << endl;
    // cout << x << " " << y << endl;
}