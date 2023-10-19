#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    string s;
    cin >> s;
    long long n;
    cin >> n;
    int x = log2(n);
    x = x + 1;
    if (x >= s.length())
    {
        long long y = 0;
        int l = s.length();
        long long j = 0;
        for (int i = l - 1; i >= 0; i--)
        {
            if (s[i] == '?')
            {
                y = y + (1 << j);
            }
            else
            {
                y = y + (s[i] - '0') * (1 << j);
            }
            j = j + 1;
        }
        if (y > n)
        {
            cout << -1 << endl;
            return;
        }
        cout << y << endl;
    }
    else
    {
        int l = s.length();
        int high = l - 1;
        string res = "";
        for (int i = 0; i < x; i++)
        {
            if (s[high] == '?')
            {
                long long hk = (1 << i) & (n);
                if (hk)
                    hk = 1;
                // cout << hk << endl;
                res += to_string(hk);
            }
            else
            {
                if (i != x - 1)
                    res += s[high];
                else
                {
                    // cout << i << endl;
                    if (s[high] == '0' && i > 0)
                    {
                        res[res.length() - 1] = '1';
                        res = s[high] + res;
                        // cout << res << endl;
                        // res[i - 1] = '1';
                    }
                    else
                        res += '1';
                }
            }
            high--;
        }
        int lr = res.length();
        long long rr = 0;
        int y = 0;
        for (int i = lr - 1; i >= 0; i--)
        {
            // cout << s[i] << endl;
            int x = res[i] - '0';
            // cout << x << endl;
            rr += x * (1 << y);
        }
        cout << rr << endl;
    }
}