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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n + 1, vector<char>(m + 1, '/'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    auto xx = v;
    while (true)
    {
        char k = '|';
        vector<int> mp(26, 0);
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (k == '|' && v[i][j] != '/')
                    k = v[i][j];
                if (v[i][j] == k)
                    mp[v[i][j] - 'a']++;
            }
            for (int j = 0; j < m; j++)
            {
                if (mp[v[i][j] - 'a'] >= 2)
                {
                    flag = 0;
                    xx[i][j] = '/';
                }
            }
            mp[k - 'a'] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k == '|' && v[j][i] != '/')
                    k = v[j][i];
                if (v[j][i] == k)
                    mp[v[j][i] - 'a']++;
            }
            for (int j = 0; j < n; j++)
            {
                if (mp[v[j][i] - 'a'] >= 2)
                {
                    flag = 0;
                    xx[j][i] = '/';
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                v[i][j] = xx[i][j];
        }
        if (flag == 1)
            break;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << xx[i][j] << " ";
            if (xx[i][j] == '/')
                continue;
            count++;
        }
        cout << endl;
    }
    cout << count << endl;
}