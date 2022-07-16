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
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int flag = 0;
        int minA = b[0];
        int maxA = b[0];
        for (int i = 1; i < n; i++)
        {
            if (b[i] >= maxA)
            {
                maxA = b[i];
            }
            else if (b[i] <= minA)
            {
                minA = b[i];
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}