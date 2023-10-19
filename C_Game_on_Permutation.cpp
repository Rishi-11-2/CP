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
        cin >> arr[i];
    int minm = arr[0];
    int minW = INT_MAX;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > minm)
        {
            if (arr[i] < minW)
            {
                minW = arr[i];
                count++;
            }
        }
        minm = min(arr[i], minm);
    }
    cout << count << endl;
}