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
    vector<int> v(202, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v[arr[i]]++;
    }
    int maxm = v[0];
    for (int i = 1; i <= 100; i++)
    {
        if (v[i] > v[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}