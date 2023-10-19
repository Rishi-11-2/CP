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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    string x1 = s1;
    string x2 = s2;
    int t, q;
    cin >> t >> q;
    vector<string> res;
    queue<pair<int, int>> queue;
    int c = 1;

    for (int i = 1; i <= q; i++)
    {

        int tp;
        cin >> tp;
        if (tp == 3)
        {
            if (s1 == s2)
                res.push_back("YES");
            else
                res.push_back("NO");
        }
        else if (tp == 1)
        {
            int idx;
            cin >> idx;
            s1[idx - 1] = '/';
            s2[idx - 1] = '/';
            queue.push({t + c - 1, idx - 1});
        }
        else if (tp == 2)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            string z1 = "";
            string z2 = "";
            if (a == 1)
                z1 = s1;
            else if (a == 2)
                z1 = s2;
            if (c == 1)
                z2 = s1;
            else if (c == 2)
                z2 = s2;
            char ch = z1[b - 1];
            z1[b - 1] = z2[d - 1];
            z2[d - 1] = ch;

            if (a == 1)
                s1 = z1;
            else if (a == 2)
                s2 = z1;

            if (c == 1)
                s1 = z2;
            else if (c == 2)
                s2 = z2;
        }
        if (queue.size() != 0)
        {
            if (queue.front().first <= c)
            {
                auto it = queue.front();
                queue.pop();
                // cout << it.second << endl;
                s1[it.second] = x1[it.second];
                s2[it.second] = x2[it.second];
            }
        }

        // cout << s1 << " " << s2 << " " << c << endl;
        c++;
    }
    for (auto it : res)
        cout << it << endl;
}