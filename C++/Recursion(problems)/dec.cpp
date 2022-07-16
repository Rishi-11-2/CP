#include <bits/stdc++.h>
using namespace std;
void dec(int n)
{
    if (n == 0)
    {
        cout << n << endl;
        return;
    }
    cout << n << endl;
    dec(n - 1);
}
void inc(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return;
    }
    inc(n - 1);
    cout << n << endl;
}
int main()
{
    int n;
    cin >> n;
    cout << "THE NUMBERS IN DECREASING ORDER ARE->";
    dec(n);
    cout << "THE NUMBERS IN INCREASING ORDER ARE->";
    inc(n);
}