#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t = 0;
        int d = arr[i + 1] - arr[i];
        for (int j = i; j < n - 1; j++)
        {
            if (d == arr[j + 1] - arr[j])
                t++;
            else
                break;
        }
        if (t > max)
            max = t;
    }

    cout << (max + 1);
}
