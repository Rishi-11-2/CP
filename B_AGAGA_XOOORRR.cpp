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
    int xr = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        xr = xr ^ arr[i];
    }
    if (xr == 0)
    {
        cout << "YES" << endl;
        return;
    }
    int c = 0;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a = a ^ arr[i];
        if (a == xr)
        {
            a = 0;
            c++;
        }
    }
    if (c >= 3)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}