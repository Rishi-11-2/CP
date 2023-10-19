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
    int s = 0;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            a++;
        }
        s += arr[i];
    }
    if (s >= 0)
    {
        if (a % 2)
        {
            cout << 1 << endl;
            return;
        }
        else
            cout << 0 << endl;
    }
    else if (s < 0)
    {
        int c = 0;
        while (s < 0)
        {
            s = s + 2;
            c++;
            a--;
        }
        if (a % 2)
            c++;
        cout << c << endl;
    }
}