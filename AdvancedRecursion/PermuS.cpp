#include <bits/stdc++.h>
using namespace std;
void permutattion(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        permutattion(ros, ans + ch);
    }
}
int main()
{
    string s;
    cin >> s;
    permutattion(s, "");
}