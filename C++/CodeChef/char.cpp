#include <iostream>
using namespace std;

int main()
{

    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char c[n];
        long t1 = 0;
        long s1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            if (c[i] == '1')
            {
                t1++;
                s1 += t1;
            }
        }

        cout << s1;
    }
    return 0;
}