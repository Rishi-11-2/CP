#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int oper = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            s = arr[i] ^ s;
            if (s != 0 and i != 0)
            {
                oper += log2(arr[i]) + 1;
                s = 0;
            }
        }
        cout << oper << endl;
    }
}