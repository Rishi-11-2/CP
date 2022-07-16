#include <bits/stdc++.h>
using namespace std;
int count(int sP, int lP)
{
    if (sP == lP)
        return 1;
    if (sP > lP)
    {
        return 0;
    }
    int S = 0;
    for (int i = 1; i <= 6; i++)
    {
        S += count(sP + i, lP);
    }
    return S;
}
int main()
{
    cout << count(0, 3);
}