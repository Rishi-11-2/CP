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
        int a = (n / 5);
        int b = (n % 5);
        int c = (a * 4) + b;
        cout << c << endl;
    }
}