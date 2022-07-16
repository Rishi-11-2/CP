#include <bits/stdc++.h>
using namespace std;
int countN(int arr[], int j, int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == j)
            t++;
    }
    return t;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sortArr[n];
    int s = 0;
    int maxE = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxE = max(arr[i], maxE);
    }
    int countArr[maxE + 1];
    int posArr[maxE + 1];
    for (int i = 0; i <= maxE; i++)
    {
        posArr[i] = 0;
    }
    for (int i = 0; i <= maxE; i++)
    {
        countArr[i] = countN(arr, i, n);
        s += countArr[i];
        posArr[i] = s;
    }
    cout << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        sortArr[posArr[arr[i]] - 1] = arr[i];
        posArr[arr[i]]--;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << sortArr[i] << " ";
    }
}