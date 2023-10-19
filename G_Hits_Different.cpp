#include <bits/stdc++.h>
using namespace std;
vector<long long> dp(2023 * 1013, 0);
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    dp[1] = 1;
    for (int i = 2; i <= 2023; i++)
    {
        long long x = i * i - i;
        x /= 2;
        x += 1;
        long long y = i * i + i;
        y /= 2;
        //  cout << x << " " << y << endl;
        for (long long k = x; k <= y; k++)
        {
            if (k == x)
            {
                dp[k] = dp[k - (i - 1)] + k * k;
            }
            else if (k == y)
            {
                dp[k] = dp[k - i] + k * k;
            }
            else
            {
                dp[k] = dp[k - i] + dp[k - (i - 1)] + k * k;
                dp[k] -= dp[k - (2 * (i - 1))];// did not come up with  . 
                // we need to subtract that are occuring multiple times.
            }
        }
    }
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}