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
    vector<unsigned long long int> v;
    for (int i = 0; i <= 63; i++)
    {
        unsigned long long int x;
        cin >> x;
        v.push_back(x);
    }
    unsigned long long int res = 0;
    unsigned long long int c = 1;
    for (int i = 0; i <= 63; i++)
    {
        res = res + (v[i] * c * 1LL);
        c = c * 2 * 1LL;
    }
    cout << res << endl;
}