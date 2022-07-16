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
        int c = (n / 4);
        if (n % 4 != 0)
        {
            c++;
        }
        cout << c << endl;
    }
}