#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int s = 0;
    int t = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s > t)
            t = s;
    }
    for (int i = 0; i < n; i++)
    {
        s -= arr[i];
        int s1 = s;
        if (s > t)
            t = s;
        for (int j = n - 1; j >= i; j--)
        {
            s1 -= arr[j];
            if (s1 > t)
                t = s1;
        }
    }
    cout << t;
}