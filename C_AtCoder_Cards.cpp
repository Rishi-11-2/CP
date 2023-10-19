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
    string h = "atcoder";
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int c1 = 0;
    int c2 = 0;
    int n = s1.length();
    map<char, int> m1;
    map<char, int> m2;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '@')
            c1++;
        if (s2[i] == '@')
            c2++;
    }
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '@')
            continue;
        m1[s1[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == '@')
            continue;
        m1[s2[i]]--;
    }
    for (auto &it : m1)
    {
        if (it.second >= 1)
        {
            // cout << it.first << endl;

            // cout << it.first << endl;
            size_t sz = h.find(it.first);
            if (sz == string::npos)
            {
                cout << "No" << endl;
                return;
            }
            else
            {
                // cout << "a";
                if (c2 > 0)
                {
                    c2 -= it.second;
                }
                else
                {
                    cout << "No" << endl;
                    return;
                }
                // cout << "a";
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == '@')
            continue;
        m2[s2[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '@')
            continue;
        m2[s1[i]]--;
    }
    for (auto &it : m2)
    {
        if (it.second >= 1)
        {
            // cout << it.first << endl;
            size_t sz = h.find(it.first);
            if (sz == string::npos)
            {
                cout << "No" << endl;
                return;
            }
            else
            {
                if (c1 > 0)
                {
                    c1 -= it.second;
                }
                else
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    if (c1 >= 0 && c2 >= 0 && c1 == c2)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}