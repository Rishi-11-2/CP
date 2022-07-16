#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int c = 0;
        int d = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                c += 1;
            }
            else
            {
                d += 1;
            }
        }
        cout << min(c, d) << endl;
    }
}