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
        int b[n];
        int s = 0;
        int d = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
            b[i] = s ^ arr[i];
            d += b[i];
            s = s ^ arr[i];
        }
        cout << d << endl;
    }
}