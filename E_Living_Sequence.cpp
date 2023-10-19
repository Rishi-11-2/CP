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
    string res = "";
    while (n > 0)
    {
        long long k = n % 9;
        if (k >= 4)
        {
            k++;
        }
        res += to_string(k);
        n /= 9;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}