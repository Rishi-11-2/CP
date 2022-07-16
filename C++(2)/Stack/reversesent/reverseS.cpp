#include <bits/stdc++.h>
using namespace std;
void reverseSentence(string s)
{
    s += " ";
    stack<string> st;
    string z = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            st.push(z);
            z = "";
        }
        z += s[i];
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{

    string s = "Hi, how are you doing?";
    reverseSentence(s);
}