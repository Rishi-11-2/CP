#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, M, L;
        cin >> N >> M >> L;

        int z = 1;
        int c = L + N - 1;

        while (z <= N)
        {
            M = M % c;
            c--;
            if (M == 0)
            {
                break;
            }
            z++;
        }
        cout << M << endl;
    }
}