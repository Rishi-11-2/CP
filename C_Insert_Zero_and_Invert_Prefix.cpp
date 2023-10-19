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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[n - 1] == 1)
    {
        cout << "NO" << endl;
        return;
    }
    int i = 0;
    int m = 0;
    int c = 0;
    vector<int> res;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] == 1 && a[i - 1] == 0)
        {
            c++;
            res.push_back(c);
            c = 0;
        }
        else if (a[i] == 1)
        {
            c++;
            res.push_back(0);
        }
        else if (a[i] == 0)
        {
            c = 0;
            res.push_back(0);
        }
    }
    if (a[0] == 1)
    {
        c++;
        res.push_back(c);
    }
    else if (a[0] == 0)
    {
        res.push_back(0);
    }
    cout << "YES" << endl;
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}