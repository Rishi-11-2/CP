#include <iostream>
using namespace std;

int main()
{

    // your code goes here
    int t;
    cin >> t;
    while (t-- > 0)
    {
        long n;
        cin >> n;
        string s;
        cin >> s;
        s[n] = '\0';
        int t = 0;
        int s1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '\0')
                break;
            if (s[i] == '1')
            {
                t++;
                s1 += t;
            }
        }
        cout << s1;
    }
    return 0;
}
