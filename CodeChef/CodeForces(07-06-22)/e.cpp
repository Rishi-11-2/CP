#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long h = 0;
        for (long long i = 0; i < n; i++)
        {
            h += (a[i] / k);
            a[i] = a[i] % k;
        }
        sort(a, a + n);
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            if ((a[low] + a[high]) >= k)
            {
                h += 1;
                low++;
                high--;
            }
            else
            {
                low++;
            }
        }
        cout << h << endl;
    }
}