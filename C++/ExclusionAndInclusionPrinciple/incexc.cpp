#include <bits/stdc++.h>
using namespace std;
int divisible(int n, int a, int b)
{
    int n1 = n / a;
    int n2 = n / b;
    int n3 = n / (a * b);
    return (n1 + n2 - n3);
}
int main()
{
    int n;
    int a, b;
    cin >> n >> a >> b;
    cout << divisible(n, a, b);
}