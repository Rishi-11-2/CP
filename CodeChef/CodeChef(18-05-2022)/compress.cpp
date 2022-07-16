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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int c = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
                continue;
            else
            {
                c++;
            }
        }
        cout << c << endl;
    }
}