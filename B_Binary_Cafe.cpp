#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
vector<vector<int>> dp;
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
    long long n, k;
    cin >> n >> k;
    long long x = 1;
    long long z = k;
    while (z > 0 && x <= n)
    {
        x = x * 2;
        z--;
    }
    if (n == k)
    {
        long long y = n * k;
        cout << y - 1 << endl;
    }
    else if (k > 31 || (1 << k) > n)
    {
        cout << n + 1 << endl;
    }
    else
    {
        cout << (1 << k) << endl;
    }
}