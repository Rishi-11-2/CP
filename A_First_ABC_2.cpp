#include <bits/stdc++.h>
#include <string>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    solve();
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string z = "ABC";
    size_t t = s.find(z);
    if (t != string::npos)
    {
        cout << t + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}