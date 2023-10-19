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
    int m = n * (n - 1);
    m /= 2;
    int arr[m];
    map<int, int> mp;
    for (int i = 0; i < (m); i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int prev = -1;
    int b[n];
    map<int, int> check;
    for (auto it : mp)
    {
        // cout << it.first << " " << it.second << endl;
        int x = it.second;
        int i = 0;
        while (x > 0)
        {
            if (check.find(i) == check.end())
            {
                int y = n - i - 1;
                if (x >= y)
                {
                    x -= y;
                    b[i] = it.first;
                    check[i] = 1;
                }
            }
            i++;
        }
    }
    int maxm = *max_element(arr, arr + m);
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            b[i] = maxm;
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
}