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
        int s = 0;
        int arr[n];
        int t = 0;

        int minS = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            minS = min(arr[i], minS);
        }
        if (x % minS == 0)
        {
            t = (x / minS);
        }
        else
        {
            t = (x / minS) + 1;
        }

        cout << max(n, t) << endl;
    }
}