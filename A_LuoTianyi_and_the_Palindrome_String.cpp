#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool isPal(string s)
{
    int n = s.length();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}
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
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (isPal(s.substr(i + 1)) == false)
        {
            cout << n - (i + 1) << endl;
            return;
        }
    }
    cout << -1 << endl;
}