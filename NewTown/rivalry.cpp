#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length;
    cin >> length;
    string s;
    cin >> s;
    int n, t;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'N')
        {
            n++;
        }

        if (s[i] == 'T')
        {

            t++;
        }
    }
    if (n > t)
    {
        cout << "Nutan";
    }
    else
    {
        cout << "Tulsa";
    }
}