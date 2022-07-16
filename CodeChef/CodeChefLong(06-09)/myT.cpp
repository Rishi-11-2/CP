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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            int l, r, x;
            cin >> l >> r >> x;
            int h = 0;
            for (int k = l - 1; k <= r - 1; k++)
            {
                if ((arr[k] xor x) > (arr[k] & x))
                {
                    h++;
                }
            }
            cout << h << endl;
        }
    }
}