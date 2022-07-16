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
        char a[n];
        char b[n];

        cin >> a;
        cin >> b;
        int h1 = n - 1;
        int h2 = n - 1;
        char c[2 * n];
        for (int i = 0; i < 2 * n; i++)
        {
            if (i % 2 == 0)
                c[i] = a[h1--];
            else
                c[i] = a[h2--];
        }
        cout << c;
    }
}