#include <bits/stdc++.h>
using namespace std;
int pow2(int bits)
{
    return 1 << bits; // 2^bits
}
int max_num(int bits)
{
    return pow2(bits + 1) - 1;
}
void solution()
{
    int n;
    cin >> n;
    int bit_count = 0;
    while (n >> bit_count)
        bit_count++;

    int ans = 0;
    for (int i = 1; i < bit_count; i++)
    {
        ans += min(n, max_num(i)) - pow2(i);
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solution();
}