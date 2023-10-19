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
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    reverse(arr, arr + n);
    int cm = INT_MAX;
    int c = 0;
    int p = 1;
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        cm = min(cm, arr[i]);
        sz++;
        if (cm * sz >= k)
        {
            c++;
            cm = INT_MAX;
            sz = 0;
        }
    }
    cout << c << endl;
}