#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;

        cin >> n >> x >> y;
        int t = 0;
        if ((x == (n) or x == (1)) and (y == 1 or y == (n)))
        {
            t = (n - 1) * 3;
        }
        else if (x == 1 or y == 1)
        {
            t = (n - 1) * 3;
        }
        else
        {
            t = (n - 1) * 4;
        }
        cout << t << endl;
    }
}