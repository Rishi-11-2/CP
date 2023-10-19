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
    vector<int> v(27, 0);
    int low = 0;
    int high = n - 1;
    int cc = 0;
    while (low <= high)
    {
        if (s[low] == s[high])
        {
            v[s[low] - 'a']++;
            cc++;
        }
        low++;
        high--;
    }
    if (cc == 0)
    {
        cout << 0 << endl;
        return;
    }
    int k = n / 2;
    if (n % 2)
        k++;
    if (cc == k)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> b;
    for (int i = 0; i <= 26; i++)
    {
        if (v[i] != 0)
            b.push_back(v[i]);
    }

    sort(b.begin(), b.end());
    // reverse(b.begin(), b.end());
    // for (auto &it : b)
    //     cout << it << " ";
    // cout << endl;
    int l = 0;
    int r = b.size() - 1;
    int res = 0;
    while (l < r)
    {
        if (b[l] > b[r])
        {
            b[l] = b[l] - b[r];
            res += b[r];
            b[r] = 0;
            r--;
        }
        else if (b[r] > b[l])
        {
            b[r] = b[r] - b[l];
            res += b[l];
            b[l] = 0;
            l++;
        }
        else
        {

            res += b[r];
            b[l] = 0;
            b[r] = 0;
            l++;
            r--;
        }
    }
    // cout << res << endl;
    for (auto &it : b)
    {
        if (it != 0)
            res += it;
    }
    cout << res << endl;
}