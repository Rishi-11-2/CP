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
    int c = 0;
    int index = -1;
    for (int i = 1; i < n - 2; i++)
    {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }
    if (n == 2 && arr[0] > arr[1])
    {
        cout << "NO" << endl;
    }
    else if (index != -1)
    {
        if (is_sorted(arr + index + 1, arr + n) && is_sorted(arr, arr + index))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
}