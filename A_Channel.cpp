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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    int pos = 0;
    int neg = 0;
    int curr = 0;
    int curr1 = 0;
    if (a == n)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < q; i++)
    {
        if (s[i] == '+')
        {
            neg++;
            pos++;
        }
        else if (s[i] == '-')
        {
            pos--;
        }
        if ((pos + a) >= n)
        {
            cout << "YES" << endl;
            return;
        }
    }
    curr = max(curr, curr1);
    if ((pos + a) >= n)
    {
        cout << "YES" << endl;
        return;
    }
    else if ((neg + a) >= n)
    {

        cout << "MAYBE" << endl;
        return;
    }
    cout << "NO" << endl;
}