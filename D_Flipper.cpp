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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    int m = n;
    if (arr[0] == m)
    {
        m--;
    }
    // cout<<m<<endl;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m)
        {
            idx = i;
            break;
        }
    }
    // cout << idx << endl;
    vector<int> res;
    if (idx == n - 1)
    {
        int h = -1;
        res.push_back(arr[idx]);
        for (int i = idx - 1; i >= 1; i--)
        {
            if (arr[i] > arr[0])
            {
                res.push_back(arr[i]);
            }
            else
            {
                h = i;
                break;
            }
        }
        if (h == -1)
            res.push_back(arr[0]);
        else
        {
            for (int i = 0; i <= h; i++)
                res.push_back(arr[i]);
        }
    }
    else
    {
        for (int i = idx; i < n; i++)
            res.push_back(arr[i]);
        int h = -1;
        res.push_back(arr[idx - 1]);
        for (int i = idx - 2; i >= 0; i--)
        {
            if (arr[i] >= arr[0])
            {
                res.push_back(arr[i]);
            }
            else
            {
                h = i;
                break;
            }
        }
        for (int i = 0; i <= h; i++)
        {
            res.push_back(arr[i]);
        }
    }
    for (auto &it : res)
        cout << it << " ";
    cout << endl;
}