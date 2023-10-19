#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] == 'l' && b[i] == '1') || (a[i] == '1' && b[i] == 'l') || (a[i] == '0' && b[i] == 'o') || (a[i] == 'o' && b[i] == '0') || a[i] == b[i])
        {
            continue;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}