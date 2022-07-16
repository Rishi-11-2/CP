#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int y = 3 * x;
        int h = 0;
        if (y < n)
        {
            h = (n / y);
        }
        cout << h << endl;
    }
}