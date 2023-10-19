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
    int c_p = 0;
    int c_n = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
            c_n++;
        if (arr[i] > 0)
            c_p++;
    }
    if (c_n == 0 || c_p == 0)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    sort(arr, arr + n);
    int low = 0;
    int high = n - 1;
    vector<int> v;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (c >= 0)
        {
            v.push_back(arr[low]);
            low++;
            c += arr[low];
        }
        else
        {
            v.push_back(arr[high]);
            high--;
            c += arr[high];
        }
    }
    for (auto &it : v)
        cout << it << " ";
    cout << endl;
}