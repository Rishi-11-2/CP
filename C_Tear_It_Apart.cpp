#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool isPowerOfTwo(int x)
{
    if (x < 0)
        return false;
    /* First x in the below expression is for the case when
     * x is 0 */
    return x && (!(x & (x - 1)));
}
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
    int n = s.length();
    vector<vector<int>> v(27);
    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[0])
            flag = 1;
    }
    if (flag == 0)
    {
        cout << 0 << endl;
        return;
    }
    // for (int i = 0; i <= 26; i++)
    // {
    //     for (int j : v[i])
    //         cout << j << " ";
    //     cout << endl;
    // }
    int minm = 1e9;
    for (char c = 'a'; c <= 'z'; c++)
    {
        int i = 0;
        // char c = (char)(k + 'a');
        int maxm = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && (((s[j] == c) && (s[i] == c)) || ((s[i] != c) && (s[j] != c))))
            {
                j++;
            }
            maxm = max(maxm, j - i);
            if (s[i] != c)
                maxm = max(maxm, j - i);
            i = j;
        }
        if (maxm == 0)
        {
            minm = 0;
            break;
        }
        int y = 0;
        // cout << maxm << endl;
        while ((1 << y) <= maxm)
        {
            y++;
        }
        minm = min(y, minm);
    }

    cout << minm << endl;
}