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
    if (n == 1)
    {
        cout << "FastestFinger" << endl;
        return;
    }
    if (n == 2)
    {
        cout << "Ashishgup" << endl;

        return;
    }
    if (n % 2)
    {
        cout << "Ashishgup" << endl;
    }
    else
    {
        int x = n / 2;
        if ((n & (n - 1)) == 0)
        {
            cout << "FastestFinger" << endl;
        }
        else
        {
            for (int i = 2; i * i <= x; i++)
            {
                if (x % i == 0)
                {
                    cout << "Ashishgup" << endl;
                    return;
                }
            }
            cout << "FastestFinger" << endl;
        }
    }
}