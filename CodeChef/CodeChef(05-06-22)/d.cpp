#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int y = l;
        y = l xor r;
        for (int i = (l + 1); i < r; i++)
        {
            int g = y;
            y = y xor i;
            if (y > l and y < r)
            {

                cout << l << " " << y << " " << i << " " << r << endl;
                break;
            }
            y = g;
        }
        cout << -1 << endl;
    }
}