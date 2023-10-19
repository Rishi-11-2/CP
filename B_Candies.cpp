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
    int n;
    cin >> n;
    vector<int> v;
    int a = n + 1;
    int b = n - 1;
    if (a % 2 != 0 && b % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        a = a / 2;
        b = b / 2;
        if (a % 2 == 0 && b % 2 == 0)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            int c = 0;
            if (a % 2 == 0)
            {
                c = b;
                v.push_back(2);
            }
            else
            {
                c = a;
                v.push_back(1);
            }
            int x = 39;
            while (x > 0)
            {
                x--;
                int a = c + 1;
                int b = c - 1;
                if (a % 2 != 0 && b % 2 != 0)
                {
                    cout << -1 << endl;
                    return;
                }
                else
                {
                    a = a / 2;
                    b = b / 2;
                    if (a % 2 == 0 && b % 2 == 0)
                    {
                        cout << -1 << endl;
                        return;
                    }
                    else
                    {
                        if (a % 2 == 0)
                        {
                            c = b;
                            v.push_back(2);
                        }
                        else
                        {
                            c = a;
                            v.push_back(1);
                        }
                    }
                    if (c == 1)
                        break;
                    if (c < 1)
                    {
                        cout << -1 << endl;
                        return;
                    }
                }
            }

            reverse(all(v));
            cout << v.size() << endl;
            for (auto &it : v)
                cout << it << " ";
            cout << endl;
        }
    }
}