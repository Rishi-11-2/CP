#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
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
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int idx = -1;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if ((n - i) < k)
        {
            k = k - (n - i);
            v.push_back(1000);
        }
        else if (k <= (n - i))
        {
            idx = i;
            if (k == 0)
            {
                idx--;
                break;
            }
            v.push_back(k);

            break;
        }
    }
    idx++;
    while (idx < n)
    {
        if (c <= (k - 1))
        {
            v.push_back(-1);
            c++;
        }
        else
            v.push_back(-2);
        idx++;
    }
    for (auto &it : v)
        cout << it << " ";
    cout << endl;
}