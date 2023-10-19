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
    string s;
    cin >> s;
    stack<char> st;
    int count = -1;
    int n = s.length();
    int flag = 1;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && s[i] == ')' && s[i - 1] == ')')
        {
            count = 0;
            one = 1;
        }
        if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                flag = 0;
                // break;
            }
        }
        else
            st.push(s[i]);
        // cout << st.size() << endl;
        if (st.size() >= 2 && one == 0)
        {
            one = 1;
            count = 0;
        }
        else if (st.size() < 2 && one == 0)
        {
            count = 1;
        }
    }
    if (st.size() != 0)
        flag = 0;
    if (n == 2 && flag == 1)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        // cout << count << endl;
        cout << "YES" << endl;
        if (count == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "(";
            }
            for (int i = 0; i < n; i++)
            {
                cout << ")";
            }
        }
        else if (count == 0)
        {
            for (int i = 0; i < 2 * n; i += 2)
            {
                cout << "()";
            }
        }
        cout << endl;
    }
}