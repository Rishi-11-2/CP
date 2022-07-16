#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if ((y - x) < 8 and (y - x) > 0)
        {
            cout << 1 << endl;
        }
        else
        {
            int a = (y - x) / 8;
            int b = (y - x) % 8;
            if (b != 0)
            {
                a += 1;
            }
            cout << (a) << endl;
        }
    }
}