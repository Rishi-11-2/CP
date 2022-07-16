#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << 3 << endl;
        }
        else if (x % 2 == 1)
        {
            cout << 1 << endl;
        }
        else if (x % 2 == 0)
        {
            int p = 0;
            int h = log2(x);
            if ((x & (x - 1)) == 0)
            {
                p = (x + 1);
            }
            else
            {
                int k = 0;
                while (x > 0)
                {
                    if ((x & 1) != 0)
                    {
                        break;
                    }
                    k += 1;
                    x = x >> 1;
                }
                p = pow(2, k);
            }
            cout << p << endl;
        }
    }
}