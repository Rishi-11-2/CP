#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[4];
    int t = 0;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for (int i = 0; i <= 3; i++)
    {
        if (a[i] >= 10)
        {
            t++;
        }
    }
    cout << t << endl;
}