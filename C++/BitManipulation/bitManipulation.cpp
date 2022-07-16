#include <bits/stdc++.h>
using namespace std;
int getBit(int n, int pos)
{
    return ((n & (1 << pos)));
}
int setBit(int n, int pos)
{
    return (n | (1 << pos)); // 1<<pos causes 1 to be at posn and zero at all other position
}
int clearBit(int n, int pos) // it clear bit at the specified positin. that is it sets it to zero.
{

    int mask = ~(1 << pos);
    return (mask & n);
}
int updateBit(int n, int pos, int value)
{
    int mask = clearBit(n, pos);
    return (mask | (value << pos));
}
int main()
{
    cout << getBit(5, 2) << endl;
    cout << setBit(5, 1) << endl;
    cout << clearBit(5, 2) << endl;
    // to update bit
    cout << updateBit(5, 1, 1) << endl;
}