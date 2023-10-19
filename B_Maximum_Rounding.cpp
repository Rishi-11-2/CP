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
    string k = s;
    reverse(all(k));
    int n = s.length();
    int flag = 0;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        int y = s[i] - '0';
        if (y >= 5)
        {
            flag = 1;
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << s << endl;
        return;
    }
    for (int j = idx; j < n; j++)
    {
        s[j] = '0';
    }
    int flagg = 0;
    for (int i = idx - 1; i >= 0; i--)
    {
        int x = s[i] - '0';
        s[i + 1] = '0';
        if (x >= 4)
        {
            if (x == 9)
                x = 10;
            else
                x++;
            s[i] = (x + '0');
            if (x == 10)
            {
                flagg = 1;
                break;
            }
        }
        else
        {
            x++;
            s[i] = (x + '0');
            break;
        }
    }
    // cout << flagg << endl;
    if (idx <= 0)
    {
        cout << "1";
    }
    cout << s << endl;
}