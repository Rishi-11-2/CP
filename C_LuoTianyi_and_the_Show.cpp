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
    int n, m;
    cin >> n >> m;
    int arr[n];
    int one = 0;
    int two = 0;
    vector<int> v;
    map<int, int> m1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == -1)
            one++;
        else if (arr[i] == -2)
            two++;
        else
        {
            if (m1[arr[i]] == 0)
            {
                v.push_back(arr[i]);
                m1[arr[i]] = 1;
            }
        }
    }
    sort(all(v));
    int res = min(m, max(one + (int)(v.size()), two + (int)(v.size())));
    for (int i = 0; i < (int)(v.size()); i++)
    {
        int ss = min(one + i, v[i] - 1) + 1 + min(two + ((int)v.size() - (i + 1)), m - v[i]); // checking for each element the maximum number of people that can be seated
        res = max(res, ss);
    }
    res = min(m, res);
    cout << res << endl;
}