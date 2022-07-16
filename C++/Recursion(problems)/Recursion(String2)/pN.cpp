#include <bits/stdc++.h>
using namespace std;
string keypadA[] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void combinations(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string code = keypadA[ch - '0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        combinations(ros, ans + code[i]);
    }
}
int main()
{
    string s;
    cin >> s;
    combinations(s, "");
}