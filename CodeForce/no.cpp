#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a, b;
        cin >> a >> b;
        int z = 1;
        while (a != b)
        {
            if (a + z > b)
            {
                b += z;
            }
            else
            {
                a += z;
            }

            z++;
        }
        cout << z - 1 << endl;
    }
}