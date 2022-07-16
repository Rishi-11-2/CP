#include <bits/stdc++.h>
using namespace std;
void process(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string ros = s.substr(1);
    char ch = s[0];
    int code = ch;
    process(ros, ans);
    process(ros, ans + ch);
    process(ros, ans + to_string(code));
}
int main()
{
    process("AB", " ");
}