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
    char a, b;
    cin >> a >> b;
    vector<int> v(8, 0);
    v[1] = 3;
    v[2] = 4;
    v[3] = 8;
    v[4] = 9;
    v[5] = 14;
    v[6] = 23;
    v[7] = 23;
    cout << abs(v[b - 'A'] - v[a - 'A']) << endl;
}