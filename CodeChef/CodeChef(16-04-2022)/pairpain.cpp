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

        int p = 0;
        int z = 0;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] == 1)
            {
                z++;
            }
            else
            {
                p++;
            }
        }

        int y = ((z * (z - 1)) / 2) + (p * z);

        cout << y << endl;
    }
}