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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int z = 0;
        for (int k = 0; k < 32; k++)
        {
            for (int i = 0; i < n; i++)
            {
                if ((arr[i] & (1 << (k))) != 0)
                {
                    z += 1;
                    break;
                }
            }
        }
        cout << z << endl;
    }
}