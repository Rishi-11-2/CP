#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string password;
        string hash;
        cin >> password;
        string str = password;
        cin >> hash;
        if (hash.length() < password.length())
        {
            cout << "NO";
            exit(0);
        }
        string hash2 = hash;
        int z = 0;
        int y = 0;
        for (int k = 0; k <= hash.length() - password.length(); k++)
        {
            str = password;
            z = 0;
            hash2 = hash.substr(k, password.length());
            cout << hash2 << endl;
            for (int i = 0; i < hash2.length(); i++)
            {
                if (str.find(hash2[i]) != string::npos)
                {
                    str = str.substr(0, str.find(hash2[i])) + str.substr(str.find(hash2[i]) + 1, str.length());
                    z += 1;
                    if (z == password.length())
                    {
                        break;
                    }
                }

                else
                {

                    z = 0;
                }
            }
            if (z == password.length())
            {
                break;
            }
        }

        if (z == password.length())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}