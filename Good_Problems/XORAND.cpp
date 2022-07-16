// Output Format
// For each test case, output the number of pairs (i,j) such that 1≤i<j≤N and  Ai⊕Aj<Ai&Aj

// Input Format
// The first line of input will contain an integer T — number of test cases. Then the test cases follow.
// Each test case contains two lines of input.
// The first line of each test case contains an integer N, the length of the array A.
// The second line of each test case contains N space-separated integers  A1,A2,…,AN

#include <bits/stdc++.h>
using namespace std;
int getMSB(int n)
{
    if (n == 0)
        return 0;
    int msb = 0;
    while (n >> msb)
    {
        msb++;
    }
    return msb;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), msbCount(32, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            int msb = getMSB(a[i]);
            msbCount[msb]++;
        }
        int64_t pairs = 0;
        for (int i = 0; i < n; i++)
        {
            int msb = getMSB(a[i]);
            pairs += max(0, msbCount[msb] - 1);
        }
        cout << pairs / 2 << endl;
    }
}