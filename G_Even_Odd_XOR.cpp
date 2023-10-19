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
    long long c = 0;
    for (int i = 1; i <= n - 3; i++)
    {
        c ^= i;
        cout << i << " ";
    }
    int x = 1 << 29;
    int y = 1 << 30;
    int z = x ^ y ^ c;
    cout << x << " " << y << " " << z << endl;
}