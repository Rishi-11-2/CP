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
    string a, b;
    cin >> a;
    cin >> b;
    int equal_n = 0;
    int diff_n = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            equal_n++;
        if (a[i] != b[i])
            diff_n++;
    }
    if (equal_n && diff_n)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int c = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                v.push_back({i + 1, i + 1});
                c++;
            }
        }
        if ((c % 2 == 0 && diff_n) || (equal_n && c % 2 == 1))
        {
            v.push_back({1, n});
            v.push_back({1, n - 1});
            v.push_back({n, n});
        }
        cout << v.size() << endl;
        for (auto &it : v)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
}