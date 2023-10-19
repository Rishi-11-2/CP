#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v;
    for (int i = 0; i < n; i++)
    {
        vector<char> a;
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            a.push_back(x);
        }
        v.push_back(a);
    }
    string p = "vika";
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == p[count])
            {
                flag = 1;
            }
        }
        if (flag == 1)
            count++;
        if (count == p.length())
            break;
    }
    if (count == p.length())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}