#include <bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    if (s.length() == 0)
        return;
    reverse(s.substr(1));
    cout << s[0];
    return;
}
int main()
{
    string s;
    cin >> s;
    reverse(s);
}