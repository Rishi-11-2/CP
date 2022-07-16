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
        int arr[n];
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                a++;
            }
            if (arr[i] == -1)
            {
                b++;
            }
        }
        if (a == b)
        {
            cout << 0 << endl;
        }
        else if ((a == 0) and (b % 2 == 0))
        {
            cout << (b / 2) << endl;
        }
        else if (b == 0 and a % 2 == 0)
        {
            cout << (a / 2) << endl;
        }
        else if (a % 2 == 0 and b % 2 == 0)
        {
            cout << min(a, b) / 2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}