#include <bits/stdc++.h>
using namespace std;
int kadane(int arr[], int n)
{
    int maxsum = INT_MIN;
    int currentsum = 0;
    for (int i = 0; i < n; i++)
    {
        currentsum += arr[i];
        if (currentsum < 0)
        {
            currentsum = 0;
        }
        maxsum = max(currentsum, maxsum);
    }
    return maxsum;
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
    int nowrapsum = kadane(arr, n);
    int wrapsum = 0;
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalsum - kadane(arr, n);
    cout << max(wrapsum, nowrapsum) << endl;
}