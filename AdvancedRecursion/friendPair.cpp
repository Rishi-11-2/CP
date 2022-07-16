#include <bits/stdc++.h>
using namespace std;
int friendPairing(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;
    return friendPairing(n - 1) + friendPairing(n - 2) * (n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << friendPairing(n);
}