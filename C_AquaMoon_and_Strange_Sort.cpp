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
    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            odd.push_back(arr[i]);
        }
        else
            even.push_back(arr[i]);
    }
    sort(all(odd));
    sort(all(even));
    reverse(all(odd));
    reverse(all(even));
    // every has to be shifted by even distance therefore , all the odd positioned elements must be at odd positon
    // similary all the even positioned elements must be at even position
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            arr[i] = odd.back();
            odd.pop_back();
        }
        else
        {
            arr[i] = even.back();
            even.pop_back();
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // reverse(arr, arr + n);
    if (is_sorted(arr, arr + n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}