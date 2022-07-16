#include <bits/stdc++.h>
using namespace std;
int pai1(int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    if (__gcd(l, r) == 1)
    {
        return (r - l);
    }
    return max(pai1(l++, r), pai1(l, r--));
}
int main()
{
    int l, r;
    cin >> l >> r;
    int t = 0;
    int s = 0;
    int l1 = l;
    int r1 = r;
    while (l1 < r1)
    {
        if (__gcd(l1, r1) == 1)
        {
            t = r1 - l1;
            s = max(s, t);
        }
        l1++;
    }
    l1 = l;
    t = 0;
    while (r1 > l1)
    {
        if (__gcd(l1, r1) == 1)
        {
            t = r1 - l1;
            s = max(s, t);
        }
        r1--;
    }
    cout << s;
}