#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char arr[n];
    cin.ignore();
    cin.getline(arr, n);
    int low = 0;
    int high = 0;
    int t = 0;

    int maxL = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == ' ' || arr[i] == '\0')
        {
            int l = i - t;
            if (l > maxL)
            {
                maxL = l;
                high = i;
                low = t;
            }
            t = i + 1;
        }
    }
    cout << "THE LONGEST WORD IS" << maxL << "  ";
    for (int i = low; i <= high; i++)
        cout << arr[i];
}