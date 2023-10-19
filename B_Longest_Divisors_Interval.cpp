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
    long long n;
    cin >> n;
    long long res = 0;
    for (long long i = 1; i <= n; i++)
    {
        if (n % i)
        {
            break;
        }
        res++;
    }
    cout << res << endl;
}