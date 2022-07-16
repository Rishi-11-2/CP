#include <bits/stdc++.h>
using namespace std;
void uniqueTwo(int arr[], int n)
{
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = x ^ arr[i];
    }
    int setBit = 0;
    int pos = 0;
    int x1 = x;
    while (setBit != 1)
    {
        setBit = x & 1;
        pos++;
        x = x >> 1;
    }
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] && (1 << (pos - 1))) != 0)
            y = y ^ arr[i];
    }
    x1 = x1 ^ y;
    cout << "TWO UNIQUE NUMBERS ARE " << x1 << " " << y;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    uniqueTwo(arr, n);
}