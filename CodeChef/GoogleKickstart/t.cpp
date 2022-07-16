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
        if (x % 2 != 0 and x != 1)
        {
            cout << 1 << endl;
        }
        if (x == 1)
        {
            cout << 3 << endl;
        }
        if (x % 2 == 0)
        {
            int k = log2(x);
            cout << ((2 * k) + 1) << endl;
        }
    }
}