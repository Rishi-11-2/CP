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
        if (n <= 26)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << (n / 26) + 1 << endl;
        }
    }
}