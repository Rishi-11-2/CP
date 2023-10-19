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
    int n, k;
    cin >> n >> k;
    int arr[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] += 1;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[0])
        {
            c++;
            if (c == k)
                break;
        }
        mp[arr[i]] = max(0, mp[arr[i]] - 1);
    }
    if (arr[0] == arr[n - 1])
    {
        if (c == k)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    else if (mp[arr[n - 1]] >= k)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}