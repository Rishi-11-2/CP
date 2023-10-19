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
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            pos.push_back(i);
    }
    if (pos.size() < 2)
    {
        cout << "YES" << endl;
        return;
    }
    int prev = pos[1] - pos[0];
    for (int i = 2; i < pos.size(); i++)
    {
        if (pos[i] - pos[i - 1] != prev)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}