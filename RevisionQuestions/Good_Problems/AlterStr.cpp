// Sample Input
// 4
// 3
// 110
// 4
// 1010
// 4
// 0000
// 7
// 1101101

// Question: For each test case, output the maximum possible length of the longest alternating substring of S after rearrangement.

// Sample Output
// 3
// 4
// 1
// 5

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = s.substr(0, n);
        int oneO = 0;
        int oneZ = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                oneZ++;
            if (s[i] == '1')
                oneO++;
        }
        int a = (oneZ != oneO) ? 1 : 0;
        cout << 2 * min(oneZ, oneO) + a << endl;
    }
}