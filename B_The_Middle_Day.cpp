#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
void solve()
{
    int m;
    cin >> m;
    int arr[m];
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    int mid = s / 2;
    mid++;
    int month = 1;
    int day = 1;
    for (int i = 0; i < m; i++)
    {
        if (mid - arr[i] > 0)
            mid -= arr[i];
        else
        {
            day = mid;
            month = i + 1;
            break;
        }
    }
    cout << month << " " << day << endl;
}