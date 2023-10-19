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
    int n, c;
    cin >> n >> c;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> mp;
    vector<int> v;
    int maxm = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] == 0)
        {
            mp[arr[i]] = 1;
            if (arr[i] != 1)
                v.push_back(arr[i]);
        }
        maxm = max(maxm, arr[i]);
    }
    for (int i = 1; i < a.size(); i++)
        a[i] += a[i - 1];
    if (mp[1] == 0)
    {
        cout << "No" << endl;
        return;
    }
    sort(all(v));
    // for (auto it : v)
    //     cout << it << " ";
    // cout << endl;
    for (int x = 2; x * maxm <= c; x++)
    {
        for (int i = 2; i <= c; i += x)
        {
            
        }
    }
    cout << "Yes" << endl;
}