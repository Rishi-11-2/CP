#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int s = 0;
    int t = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s < 0)
        {
            s = 0;
        }
        if (s > t)
        {
            t = s;
        }
    }
    cout << t;
}