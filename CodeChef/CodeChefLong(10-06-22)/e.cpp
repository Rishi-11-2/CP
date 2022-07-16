#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int n = abs(b - a);

        // Traversing through to calculate the numbe rof divisors
        int total = 0;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (n / i == i)
                {
                    total += 1;
                }
                else
                {
                    total += 2;
                }
            }
        }
        cout << total << endl;
    }
}
