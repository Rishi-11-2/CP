#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "adj";
    s1.clear();
    if (s1.empty()) // check whether the string is empty
    {
        cout << "THE STRING IS EMPTY" << endl;
    }
    string s2 = "nincompoop";
    cout << s2.find("poo") << endl;
    s2.erase(3, 2);
    s2.insert(2, "lololololol");
    cout << s2.length() << endl;

    cout << s2 << endl;
    for (int i = 0; i < s2.length(); i++)
        cout << s2[i] << "  ";
    cout << " " << endl;
    string z = s2.substr(6, 4);
    cout << z << endl;

    string a = "7654";
    int x = stoi(a); // convets to ineteger
    cout << x * 100 << endl;
    string a1 = to_string(x) + "I AM WERT";
    cout << a1 << endl;
}