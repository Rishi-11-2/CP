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
    int c = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == (i + 1))
        {
            if (flag == 1)
            {
                flag = 0;
                c++;
            }
        }
        else if (arr[i] != i + 1)
        {
            flag = 1;
        }
    }
    if (flag == 1)
        c++;
    if (c > 1)
    {
        cout << 2 << endl;
    }
    else if (c == 1)
    {
        cout << 1 << endl;
    }
    else
        cout << 0 << endl;
}