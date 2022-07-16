#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    const int N = 1e5;
    int g[N];
    for (int i = 0; i < N; i++)
        g[i] = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            g[arr[i]] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        if (g[i] == -1)
        {
            cout << (i);
            break;
        }
    }
    return 0;
}