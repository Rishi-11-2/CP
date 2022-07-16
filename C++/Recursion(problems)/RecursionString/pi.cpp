#include <bits/stdc++.h>
using namespace std;
string z = "";
void pi(string s)
{
    if (s.length() == 0)
        return;
    string p = s.substr(0, 2);
    if (p == "pi")
    {
        z += "3.14";
        pi(s.substr(2));
    }
    else
    {
        z += s.substr(0, 1);
        pi(s.substr(1));
    }
}
int main()
{
    string s;
    cin >> s;
    pi(s);
    cout << z;
}