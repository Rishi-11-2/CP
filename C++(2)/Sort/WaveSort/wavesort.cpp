#include <bits/stdc++.h>
using namespace std;
void swap(int arr[], int i, int j)
{
    int t = arr[j];
    arr[j] = arr[i];
    arr[i] = t;
}
void wavesort(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr, i, i - 1);
        }
        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            swap(arr, i, i + 1);
        }
    }
}
int main()
{
    int arr[] = {1, 3, 4, 7, 5, 6, 2};
    wavesort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
}
// Time Complexity =O(n/2)