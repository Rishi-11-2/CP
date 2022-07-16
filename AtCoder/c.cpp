#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    int b;
    cin >> a >> b;
    if (a == 1 && b == 10 || a == 10 && b == 1)
        cout << "YES";
    else
    {
        if (a + 1 == b || a == b + 1)
            cout << "YES";
        else
            cout << "NO";
    }
}