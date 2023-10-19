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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int res = 0;
    map<int, int> m;
    int inv = 0;
    int t1 = 1;
    int t2 = 1;
    int c1 = 0, c2 = 0;
    map<int, int> m;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1] && b[i] == b[i - 1])
        {
            c += 2;
        }
        else if (a[i] == a[i - 1])
        {
            if (inv == 0)
                c++;
            else
            {
                inv = 1;
                res = max(res, c);
                c = 1;
            }
        }
        else if (b[i] == b[i - 1])
        {
            c++;
        }
    }
    c1 = max(c1, t1);
    c2 = max(c2, t2);
    cout << max(c2, c1) << endl;
}