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
    int s;
    cin >> s;
    int y = 0;
    int t = 0;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        l = i;
        y += arr[i];
        if (y > s)
        {
            y -= arr[t++];
        }
        if (y == s)
        {
            break;
        }
    }
    cout << (t + 1) << " " << (l + 1);
    return 0;
}