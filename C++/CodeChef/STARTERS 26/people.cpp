#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int maxPeople = INT_MIN;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            x += arr[i];
            maxPeople = max(x, maxPeople);
        }
        cout << maxPeople << endl;
    }
}