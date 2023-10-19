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
    int a, b;
    cin >> a >> b;
    if (a % 3 == 1 && b % 3 == 2 && a + 1 == b)
        cout << "Yes" << endl;
    else if (a % 3 == 2 && b % 3 == 0 && a + 1 == b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}