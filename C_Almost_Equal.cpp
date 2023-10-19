#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int diff(string a, string b)
{
    int d = 0;
    int m = a.length();
    for (int i = 0; i < m; i++)
    {
        if (a[i] != b[i])
            d++;
    }
    return d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    map<int, int> m1;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (m1[j] == 2 || m1[i] == 2)
                continue;
            if (j == i)
                continue;
            if (diff(s[i], s[j]) == 1)
            {
                flag = 1;
                m1[i] += 1;
                m1[j] += 1;
                // break;
            }
        }
        if (flag == 0)
            m1[i] = -1;
    }
    int c1 = 0;
    int c2 = 0;
    for (auto &it : m1)
    {
        if (it.second == 1)
            c1++;
        else if (it.second == 2)
            c2++;
    }
    if (c1 > 2)
    {
        cout << "No" << endl;
        return;
    }
    else if (c1 + c2 == n)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "Yes" << endl;
}