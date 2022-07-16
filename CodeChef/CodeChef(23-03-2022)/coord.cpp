#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    int x = 0;
    while (t-- > 0)
    {
        x = 0;
        int n;
        cin >> n;
        if (n % 2 != 0)
        {
            x = (ceil(n / 2) + 1) * (-1);
        }
        else
        {
            x = (n / 2);
        }
        cout << x << endl;
    }
}