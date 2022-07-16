#include <bits/stdc++.h>
using namespace std;
bool adjacent(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n - 1; i++)
    {
        s += arr[i] * arr[i + 1];
    }
    return (s % 2 == 0) ? false : true;
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int z = 0;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (adjacent(arr, n))
        {
            z = 1;
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                swap(arr[i], arr[j]);
                if (adjacent(arr, n))
                {
                    z = 1;
                    break;
                }
            }
        }
        if (z == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}