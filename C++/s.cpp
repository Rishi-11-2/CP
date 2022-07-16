#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "RISHICHOWDHURY";
    string str1(5, 'n');
    cout << str1 << " " << str << endl;
    getline(cin, str);
    cout << str << endl;
    ;
    string s1 = "fam";
    string s2 = "ily";
    // s1.append(s2);
    // cout << s1;
    cout << s1[1] << endl;
    cout << s1 + s2 << endl;
    string abc = "  fffjehf j feefff";
    cout << abc << endl;
    abc.clear(); // clear function removes all the string
    cout << abc << endl;
    cout << s1.compare(s2);
}