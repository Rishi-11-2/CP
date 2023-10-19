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
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr[n] = arr[n - 1];
    int count = 1;
    int i = 0;
    int j = 0;
    while (i < n)
    {
        // res.push_back(arr[i]);
        j = i + 1;
        if (j >= n)
            break;
        while (j < n && arr[j] == arr[j - 1])
            j++;
        if (j >= n)
            break;
        // i = j;
        if (arr[i] < arr[j])
        {
            while (j < n && arr[j] <= arr[j + 1])
            {
                j++;
                // i++;
            }
            count++;
        }
        else if (arr[i] > arr[j])
        {
            while (j < n && arr[j] >= arr[j + 1])
            {
                j++;
            }
            count++;
        }
        i = j;
    }
    cout << count << endl;
}