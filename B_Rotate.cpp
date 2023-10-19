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
    int n;
    cin >> n;
    int arr[n][n];
    int b[n][n];
    memset(arr, 0, sizeof(arr));
    memset(b, 0, sizeof(b));
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = v[i][j] - '0';
        }
    }
    for (int i = 1; i < n; i++)
    {
        b[0][i] = v[0][i - 1] - '0';
    }
    for (int i = 1; i < n; i++)
    {
        b[i][n - 1] = v[i - 1][n - 1] - '0';
    }
    for (int i = n - 2; i >= 0; i--)
    {
        b[n - 1][i] = v[n - 1][i + 1] - '0';
    }
    for (int i = n - 2; i >= 0; i--)
    {
        b[i][0] = v[i + 1][0] - '0';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << b[i][j];
        cout << endl;
    }
}