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
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = n - 1;
    int flag1 = 0;
    int flag3 = 0;
    int flag4 = 0;
    int i = 1;
    int j = n;
    int flag2 = 0;
    while (low <= high)
    {
        flag1 = 0;
        flag2 = 0;
        if (arr[low] == i)
        {
            low++;
            i++;
            flag1 = 1;
        }
        else if (arr[low] == j)
        {
            j--;
            low++;
            flag3 = 1;
        }
        else if (arr[high] == i)
        {
            i++;
            high--;
            flag4 = 1;
        }
        else if (arr[high] == j)
        {
            j--;
            high--;
            flag2 = 1;
        }
        else
            break;
    }
    if (low >= high)
        cout << -1 << endl;
    else
    {
        cout << 1 + low << " " << 1 + high << endl;
    }
}