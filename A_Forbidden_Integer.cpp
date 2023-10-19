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
    long long n, k, x;
    cin >> n >> k >> x;
    if (x != 1)
    {
        cout << "YES" << endl;
        cout << n << endl;
        for (long long i = 1; i <= n; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else
    {
        set<int> s;
        for (long long i = 2; i <= k; i++)
        {
            if (i == x)
                continue;
            if (n % i == 0)
            {
                long long a = n / i;
                cout << "YES" << endl;
                cout << a << endl;
                for (long long j = 1; j <= a; j++)
                {
                    cout << i << " ";
                }
                cout << endl;
                return;
            }
            if (s.find(n - i) != s.end())
            {
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << i << " " << n - i << endl;
                return;
            }
            s.insert(i);
        }
        cout << "NO" << endl;
    }
}