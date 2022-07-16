#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char arr[n];
    cin.ignore();
    cin.getline(arr, n);
    cin.ignore();
    int low = 0;
    int high = 0;
    int t = 0;
    int max = INT_MIN;
    for (int i = 0; i < n + 1; i++)
    {
        if (arr[i] == ' ')
        {
            if (max < (i - t))
            {
                max = (i - t);
                high = i;
                low = 0;
            }

            t = i + 1;
        }
    }
    cout << "THE LONGEST WORD->";
    for (int i = low; i <= high; i++)
    {
        cout << arr[i];
    }
    cout << "THE LENGTH OF THE LONGEST WORD IS ->" << max;
}