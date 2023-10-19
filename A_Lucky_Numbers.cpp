#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int cal(int n)
{
    int maxN = 0;
    int minM = 11;
    int c = 0;
    while (n > 0)
    {
        int r = n % 10;
        n /= 10;
        maxN = max(maxN, r);
        minM = min(minM, r);
        c++;
    }
    // cout << c << endl;
    // cout << maxN << " " << minM << endl;
    return (maxN - minM);
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
    int l, r;
    cin >> l >> r;
    int maxm = -1;
    int num = 0;
    int c = 0;
    for (int i = l; i <= r; i++)
    {
        // c++;
        int diff = cal(i);
        if (diff > maxm)
        {
            maxm = diff;
            num = i;
        }
        if (maxm == 9)
            break;
    }
    cout << num << endl;
}