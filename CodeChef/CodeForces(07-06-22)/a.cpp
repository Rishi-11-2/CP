#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double n;
        cin >> n;
        double b = ceil(n / 3);
        double a = (b + 1);
        double c = (n - (a + b));
        if (c != 0)
        {
            cout << b << " " << a << " " << c << endl;
        }
        else
        {
            b--;
            c++;
            cout << b << " " << a << " " << c << endl;
        }
    }
}