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
        long long int p = 0;
        long long int e = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 0)
            {
                p++;
            }
            if (arr[i] < 0)
            {
                e++;
            }
        }
        long long int P = 0;
        if (p != 0 and p != 1)
        {
            P = (p * (p - 1)) / 2;
        }
        long long int E = 0;
        if (e != 0 and e != 1)
        {
            E = (e * (e - 1)) / 2;
        }
        cout << (P + E) << endl;
    }
}