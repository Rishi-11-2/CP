#include <bits/stdc++.h>
using namespace std;
class base
{
public:
    virtual void print()
    {
        cout << "This is the base class 's print function" << endl;
    }
    void display()
    {
        cout << "This is the base class's display function" << endl;
    }
};
class derived : public base
{
public:
    void print()
    {
        cout << "This is the derived class 's print function" << endl;
    }
    void display()
    {
        cout << "This is the derived class's display function" << endl;
    }
};
int32_t main()
{
    base *baseptr;
    derived d;
    base b;
    baseptr = &d; // even though pointer points to derived classs base class function will get executed
    // in order for dervied class function to get executed we will use a virtual keyword in front of base's class function
    baseptr->print();
    baseptr->display();
    b.display();
    d.display();
}