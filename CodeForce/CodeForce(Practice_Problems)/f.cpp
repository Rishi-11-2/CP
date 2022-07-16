#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int h = 0;
        if (b > a)
        {
            h++;
        }
        if (c > a)
        {
            h++;
        }
        if (d > a)
        {
            h++;
        }
        cout << h << endl;
    }
}