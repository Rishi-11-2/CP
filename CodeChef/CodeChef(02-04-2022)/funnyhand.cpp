#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int z = 0;
        int p = 0;
        if (a == 1 || b == 1 || a == n || b == n)
        {
            z = 1;
        }
        if (abs(b - a) == 1)
        {
            if (z == 1)
            {
                p = 1;
            }
            else
            {
                p = 2;
            }
        }
        if (abs(b - a) == 2)
        {
            p = 1;
        }
        if (abs(b - a) > 2 || abs(b - a) < 1)
        {
            p = 0;
        }
        cout << p << endl;
    }
}