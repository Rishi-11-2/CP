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
    string s;
    cin >> s;
    if (n % 2)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> res(n, 0);
    stack<pair<char, int>> st;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (!st.empty())
        {
            if (st.top().first == '(' && s[i] == ')')
            {
                res[st.top().second] = 1;
                res[i] = 1;
                st.pop();
            }
            else if (st.top().first == ')' && s[i] == '(')
            {
                res[st.top().second] = 2;
                res[i] = 2;
                st.pop();
            }
            else
                st.push({s[i], i});
        }
        else
        {
            st.push({s[i], i});
        }
    }
    if (!st.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        map<int, int> m;
        for (auto &it : res)
            m[it] = 1;
        int c = 0;
        for (auto &it : m)
        {
            if (it.second > 0)
                c++;
        }
        cout << c << endl;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({res[i], i});
        }
        sort(all(v));
        int k = 1;
        res[0] = k;
        for (int i = 1; i < n; i++)
        {
            if (v[i].first > v[i - 1].first)
            {
                k++;
                res[v[i].second] = k;
            }
            else
                res[v[i].second] = k;
        }
        for (auto &it : res)
            cout << it << " ";
        cout << endl;
    }
}