#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
ll powerLL(ll x, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}
ll powerStrings(string sa, string sb)
{
    // We convert strings to number

    ll a = 0, b = 0;

    // calculating a % MOD
    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (sa[i] - '0')) % MOD;

    // calculating b % (MOD - 1)
    for (int i = 0; i < sb.length(); i++)
        b = (b * 10 + (sb[i] - '0')) % (MOD - 1);

    // Now a and b are long long int. We
    // calculate a^b using modulo exponentiation
    // cout << a << " " << b << endl;
    return powerLL(a, b);
}
void solve();
int32_t main()
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
    for (int i = 1; i <= n; i++)
    {
        int n1, m1;
        cin >> n1 >> m1;
        string a = to_string(n1);
        string b = to_string(m1);
        cout << powerStrings(b, a) << endl;
    }
}