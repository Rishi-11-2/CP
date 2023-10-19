#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
/* Concept : The least Significant Bit Of Any Number is the divisor of that Number
We can use this concept to convert the given number into a power of 2. After that we can just
reduce that power of 2 by one less power of 2 stating that we can reduce any power of 2.
We will be using every d  twice.  */
void solve()
{
    int n;
    cin >> n;
    int x = n;
    int p = 0;
    vector<int> ans;
    ans.push_back(x);
    for (int i = 0;; i++)
    {
        if (x & (1 << i))
        {
            if (x == (1 << i))
            {
                p = i;
                break;
            }
            x -= (1 << i);
            ans.push_back(x);
        }
    }
    while (p > 0)
    {
        x -= (1 << (p - 1));
        ans.push_back(x);
        p--;
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}