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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> count(n, 0);
    stack<pair<int, int>> st;
    int tc = 0;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        char z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            s[y - 1] = z;
            count[y - 1] = i;
        }
        else
        {
            if (x == 2)
                st.push({2, i});
            else
                st.push({3, i});
        }
        // cout << s << endl;
    }
    // cout << s << endl;
    auto it = st.top();
    for (int i = 0; i < n; i++)
    {
        if (count[i] < it.second)
        {
            // cout << i << endl;
            if (it.first == 3)
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    continue;
                }
                s[i] = s[i] - 32;
            }
            else if (it.first == 2)
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                    continue;
                s[i] = s[i] + 32;
            }
        }
    }
    cout << s << endl;
}