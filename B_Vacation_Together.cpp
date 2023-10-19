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
    int n, d;
    cin >> n >> d;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    // for (int i = 0; i < n; i++)
    //     cout << v[i] << endl;
    int res = 0;
    int curr = 0;
    for (int i = 0; i < d; i++)
    {
        int flag = 0;
        if (v[0][i] == 'o')
        {
            for (int j = 1; j < n; j++)
            {
                if (v[j][i] != 'o')
                {
                    flag = 1;
                    break;
                }
            }
        }
        else
            flag = 1;
        if (flag)
        {
            res = max(res, curr);
            curr = 0;
        }
        else
            curr++;
    }
    res = max(res, curr);
    cout << res << endl;
}