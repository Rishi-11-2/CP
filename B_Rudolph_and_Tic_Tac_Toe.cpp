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
    vector<vector<char>> v(3, vector<char>(3, '/'));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            v[i][j] = c;
        }
    }
    // for (auto it : v)
    // {
    //     for (auto i : it)
    //         cout << i << " ";
    //     cout << endl;
    // }
    for (int i = 0; i < 3; i++)
    {
        char prev = v[i][0];
        int flag = 0;
        for (int j = 1; j < 3; j++)
        {
            if (prev != v[i][j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag && prev != '.')
        {
            cout << prev << endl;
            return;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        char prev = v[0][i];
        int flag = 0;
        for (int j = 1; j < 3; j++)
        {
            if (prev != v[j][i])
            {
                flag = 1;
                break;
            }
        }
        if (!flag && prev != '.')
        {
            cout << prev << endl;
            return;
        }
    }
    char prev = v[0][0];
    int flag = 0;
    for (int i = 1; i < 3; i++)
    {
        if (prev != v[i][i])
        {
            flag = 1;
            break;
        }
    }
    if (!flag && prev != '.')
    {
        cout << prev << endl;
        return;
    }
    prev = v[0][2];
    flag = 0;
    for (int i = 1; i >= 0; i--)
    {
        if (prev != v[2 - i][i])
        {
            flag = 1;
            break;
        }
    }
    if (!flag && prev != '.')
    {
        cout << prev << endl;
        return;
    }
    cout << "DRAW" << endl;
}