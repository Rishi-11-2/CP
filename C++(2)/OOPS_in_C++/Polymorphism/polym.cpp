#include <bits/stdc++.h>
using namespace std;
class Poly
{
public:
    void func()
    {
        cout << "I am a functio with no argument" << endl;
    }
    void func(int x)
    {
        cout << "I am a functio with an int argument" << endl;
    }
    void func(double x)
    {
        cout << "I am a functio with a double argument" << endl;
    }
};
int32_t main()
{
    Poly Obj;
    Obj.func();
    Obj.func(4);
    Obj.func(100.120);
}