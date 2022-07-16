#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> strs)
{
    string s = "";
    int index = 0;
    int minL = INT_MAX;
    string z = "";
    for (int i = 0; i < (int)(strs.size()); i++)
    {
        if (minL > strs[i].length())
        {
            minL = strs[i].length();
            z = strs[i];
            index = i;
        }
    }
    int y = 0;
    for (int i = 0; i < z.length(); i++)
    {
        for (int j = 0; j < (int)(strs.size()); j++)
        {
            if (index != j and z[i] == strs[j][i])
            {
                y++;
            }
        }
        if (y == (int)(strs.size()) - 1)
        {
            s += z[i];
            y = 0;
        }
        else
        {
            break;
        }
    }

    return s;
}
int main()
{
    string strs[] = {"dog", "racecar", "car"};
    vector<string> s;
    for (int i = 0; i < 3; i++)
    {
        s.push_back(strs[i]);
    }
    string a = longestCommonPrefix(s);
    cout << a;
}