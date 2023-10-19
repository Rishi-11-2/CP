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
    long long a, b;
    cin >> a >> b;
    long long x = a / b;
    if (a % b)
    {
        x++;
    }
    cout << x << endl;
}