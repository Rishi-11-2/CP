#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t-- > 0)
    {
        int i;
        cin >> i;
        int s = 0;
        if (i < 3)
        {
            cout << 0 << endl;
        }
        if (i == 3)
        {
            cout << 1 << endl;
        }
        if (i >= 4)
        {

            int z = log2(i);
            s = pow(2, z) - (z + 1);
            if (ceil(log2(i)) != floor(log2(i)))
            {
                s += ((i - (pow(2, z))) - 1);
            }
            cout << s << endl;
        }
    }
}