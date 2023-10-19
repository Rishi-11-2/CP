#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
vector<int> fib(51, 0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 50; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    function<int(int, int, int)> f = [&](int n, int x, int y) -> int
    {
        if (n == 1)
            return 1;
        if (fib[n - 1] <= y && y < fib[n])
        {
            return 0;
        }
        if (y >= fib[n])
        {
            y -= fib[n];
        }
        return f(n - 1, y, x);
    };
    if (f(n, x - 1, y - 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}