#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
long long dp[101][250][2];
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
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    int n = max(a.length(), b.length());
    vector<int> v1;
    vector<int> v2;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++)
    {
        v1.push_back(a[i] - '0');
    }
    for (int i = a.length(); i < n; i++)
    {
        v1.push_back(0);
    }
    for (int i = 0; i < b.length(); i++)
    {
        v2.push_back(b[i] - '0');
    }
    for (int i = b.length(); i < n; i++)
        v2.push_back(0);
    reverse(all(v1));
    reverse(all(v2));
    int flag = 0;
    // for (auto it : v1)
    //     cout << it << " ";
    // cout << endl;
    // for (auto it : v2)
    //     cout << it << " ";
    // cout << endl;
    long long res = 0;
    if (v1[0] != v2[0])
        flag = 1;
    for (int i = 1; i < n; i++)
    {
        // cout << v1[i] << " " << v2[i] << endl;
        if (flag)
            res += 9;
        else
        {
            res += abs(v1[i] - v2[i]);
            if (v1[i] != v2[i])
                flag = 1;
        }
    }
    res += abs(v1[0] - v2[0]);
    cout << res << endl;
}