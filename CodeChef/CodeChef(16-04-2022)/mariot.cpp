#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string s[] = {"NORMAL", "HUGE", "SMALL"};
        int z = 1;
        z = (x % 3);
        cout << s[z] << endl;
    }
}