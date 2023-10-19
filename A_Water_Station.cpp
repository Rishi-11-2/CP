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
    int x = n / 10;
    x = x * 10;
    int y = x + 5;
    if (abs(n - x) > abs(n - y))
        cout << y << endl;
    else
        cout << x << endl;
}