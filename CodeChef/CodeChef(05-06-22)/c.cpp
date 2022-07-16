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
        int maxE = arr[0] + arr[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            maxE = max(maxE, arr[i] + arr[i + 1]);
        }
        cout << maxE << endl;
    }
}