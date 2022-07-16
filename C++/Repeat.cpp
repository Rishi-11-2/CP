#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "HELLO WOLRD";
    const long int N = 1e4;
    int g[N];
    for (int i = 0; i < N; i++)
    {
        g[i] = -1;
    }

    cout << "HELLO WOLRD";
    int minI = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (g[arr[i]] != -1)
        {
            if (minI > g[arr[i]])
                minI = g[arr[i]];
        }
        else
            g[arr[i]] = (i);
    }

    cout << minI + 1;
    cout << "HELLO WOLRD";
    return 0;
}