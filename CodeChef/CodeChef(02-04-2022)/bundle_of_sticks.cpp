#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int arr[100] = {0};
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            arr[a[i] - 1] += 1;
        }
        int z = 0;
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] % 2 != 0)
                z += 1;
        }
        if (n == 1)
        {
            z = 3;
        }
        if (n == 2)
        {
            z = 2;
        }
        if ((z + n) % 4 != 0)
        {
            z = z + ((z + n) % 4);
        }
        cout << z << endl;
    }
}