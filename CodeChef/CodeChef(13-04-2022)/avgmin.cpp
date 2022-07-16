#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        int s = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr[n];
            s += arr[n];
        }
        int y = (n * x) - s;
        if (y > 0)
        {
            cout << y << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}