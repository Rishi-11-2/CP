#include <bits/stdc++.h>
using namespace std;
bool search(int arr[], int n, int k1)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k1)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << high << " " << low << endl;
            high--;
            low++;
        }
        else if (arr[low] + arr[high] < k)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
}
