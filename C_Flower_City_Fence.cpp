#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
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
        cin >> arr[i];
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    int x = arr[0];
    int mid = (n - 1) / 2;
    int diff = arr[0] - arr[mid];
    for (int i = 1; i < n; i++)
    {
        int nd = arr[i - 1] - arr[i];
        if (nd > diff)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}