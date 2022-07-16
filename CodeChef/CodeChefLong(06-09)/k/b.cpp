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
        int minM = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            minM = min(minM, arr[i]);
        }
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            if (minM != arr[i])
            {
                s += (arr[i] - minM);
            }
        }
        cout << s << endl;
    }
}