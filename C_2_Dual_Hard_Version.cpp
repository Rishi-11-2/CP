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
    int arr[n];
    int flag = -1;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            flag = 1;
            idx = i;
            break;
        }
        else if (arr[i] < 0)
            flag = 0;
    }
    if (flag == 1)
    {
        vector<pair<int, int>> v;
        while (arr[idx] < 20)
        {
            arr[idx] += arr[idx];
            v.push_back({idx + 1, idx + 1});
        }
        int c = arr[idx];
        // cout << c << endl;
        for (int i = 1; i < n; i++)
        {
            while (arr[i] <= c)
            {
                // cout << "h" << endl;
                arr[i] = arr[i] + c;
                v.push_back({i + 1, idx + 1});
            }
            idx = i;
            c = arr[i];
        }
        cout << v.size() << endl;
        for (auto it : v)
            cout << it.first << " " << it.second << endl;
    }
    else if (flag == 0)
    {
        vector<pair<int, int>> v;

        for (int i = n - 1; i >= 1; i--)
        {
            v.push_back({i, i + 1});
        }
        v.push_back({1, 1});
        cout << v.size() << endl;
        for (auto it : v)
            cout << it.first << " " << it.second << endl;
    }
    else
        cout << 0 << endl;
}