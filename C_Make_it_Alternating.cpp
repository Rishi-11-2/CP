#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    string s;
    cin >> s;
    long long n = s.length();
    long long res = 1;
    long long count = 0;
    long long mod = 998244353;
    long long i = 0;
    while (i < n)
    {
        long long j = i;
        long long flag = 0;
        long long c = 0;
        while (j < n && s[i] == s[j])
        {
            j++;
            c++;
            if (flag == 0)
            {
                count++;
            }
            flag = 1 - flag;
        }
        i = j;
        if (c == 1)
            count--;
        if (c > 1)
            res = ((res % mod) * (c % mod) * ((c - 1) % mod)) % mod;
    }
    if (count > 1)
        res = ((res % mod) * (count % mod) * ((count - 1) % mod)) % mod;
    cout << count << " " << res << endl;
}