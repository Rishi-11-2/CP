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
    int minm = INT_MAX;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        minm = min(minm, arr[i]);
        if (arr[i] % 2)
            flag = 1;
    }
    if (minm % 2)
    {
        cout << "YES" << endl;
    }
    else if (minm % 2 == 0 && flag == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}