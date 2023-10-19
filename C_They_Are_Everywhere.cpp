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

    solve();
}
bool isCompare(map<char, int> mp, map<char, int> slide)
{
    for (auto it : mp)
    {
        if (slide[it.first] < it.second)
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]] = 1;
    }
    map<char, int> slide;
    int i = 0;
    int j = 0;
    int res = INT_MAX;
    while (j < n && i <= j)
    {
        if (isCompare(mp, slide))
        {
            res = min(res, j - i);
            while (isCompare(mp, slide))
            {
                slide[s[i]] = max(slide[s[i]] - 1, 0);
                i++;
            }
            res = min(res, j - (i - 1));
        }
        slide[s[j]]++;
        j++;
    }
    while (isCompare(mp, slide))
    {
        slide[s[i]] = max(slide[s[i]] - 1, 0);
        i++;
    }
    res = min(res, j - (i - 1));
    cout << res << endl;
}