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
    string z = s;
    sort(z.begin(), z.end());
    string res = "";
    int i = 0;
    int c = 0;
    while (s[i] == z[0])
    {
        i++;
        c++;
    }
    int index = -1;
    for (int j = i; j < n; j++)
    {
        if (s[j] == z[0])
        {
            index = j;
        }
    }
    if (index == -1)
        cout << s << endl;
    else
    {
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (i != index)
                res += s[i];
        }
        res = s[index] + res;
        cout << res << endl;
    }
}