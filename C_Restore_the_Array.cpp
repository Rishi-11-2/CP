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
    int b[n - 1];
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];
    vector<int> v;
    int flag = 0;
    int clfag = 0;
    int v2 = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (b[i] < b[i - 1])
            v2 = 1;
    }
    if (v2 == 0)
    {
        cout << 0 << " ";
        for (int i = 0; i < n - 1; i++)
            cout << b[i] << " ";
        cout << endl;
        return;
    }
    int v1 = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (b[i - 1] < b[i])
        {
            v1 = 1;
        }
    }
    if (v1 == 0)
    {
        for (int i = 0; i < n - 1; i++)
            cout << b[i] << " ";
        cout << 0 << endl;
        return;
    }
    v.push_back(b[0]);
    for (int i = 1; i < n - 1; i++)
        v.push_back(min(b[i - 1], b[i]));
    v.push_back(b[n - 2]);
    for (auto &it : v)
        cout << it << " ";
    cout << endl;
}