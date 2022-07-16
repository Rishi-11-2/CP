#include <bits/stdc++.h>

using namespace std;

int solve(int arr[], int n, int a, int b, int i, int curr)
{
    if (i == n)
        return 0;

    int s = 0;

    s = (arr[i] - curr) * b;

    int x = solve(arr, n, a, b, i + 1, curr);
    int z = (arr[i] - curr) * a;
    int y = solve(arr, n, a, b, i + 1, curr + 1);

    s = min(s + x, s + y + z);
    return s;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n, a, b, 0, 0);
    }
}