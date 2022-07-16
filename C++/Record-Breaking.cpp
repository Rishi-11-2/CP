#include <iostream>
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
    int t = 0;
    if (arr[0] > arr[1])

        t++;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            t++;
    }
    if (arr[n - 1] > arr[n - 2])
        t++;
    cout << t;
}