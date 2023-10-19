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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]].push_back(i);
    }
    for (auto it : mp)
    {
        auto v = it.second;
        int sz = (int)(v.size());
        char c = s[v[sz - 1]];
        // cout << c << endl;
        for (int i = sz - 1; i >= 1; i--)
        {
            // cout << v[i] << " ";
            s[v[i]] = s[v[i - 1]];
        }
        // cout << endl;
        s[v[0]] = c;
        // cout << s << endl;
    }
    cout << s << endl;
}