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
    long long c = 0;
    while (a >= 1 && b >= 1)
    {
        int g = __gcd(a, b);
        a = a - g;
        b = b - g;
        c++;
    }
    cout << c << endl;
}