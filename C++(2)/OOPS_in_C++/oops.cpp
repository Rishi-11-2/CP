#include <bits/stdc++.h>
using namespace std;
class student
{
    string name;

public:
    int age;
    bool gender;
    student()
    {
        cout << "this is default constructor" << endl;
    }
    student(string s, int a, bool g)
    {
        name = s;
        age = a;
        gender = g;
    }
    student(student &a)
    {
        cout << "COPY CONSTRUCTOR" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    ~student()
    {
        cout << "DESTRUCTOR CALLED" << endl;
    }
    void getName()
    {
        cout << name << endl;
    }
    void setName(string s)
    {
        name = s;
    }
    void printInfo()
    {
        cout << "Name =";
        cout << name << endl;
        cout << "age =";
        cout << age << endl;
        cout << "gender =";
        cout << gender << endl;
    }
    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }
};
int main()
{

    // student arr[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     string s;
    //     cout << "Name =";
    //     cin >> s;
    //     arr[i].setName(s);
    //     cout << "age =";
    //     cin >> s;
    //     arr[i].setName(s);
    //     cout << "gender =";
    //     cin >> s;
    //     arr[i].setName(s);

    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].printInfo();
    // }
    student a("Rishi", 18, 0);
    student b("AD", 21, 0);
    student c = a;
    c.getName();
    if (a == c)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not same" << endl;
    }
    if (a == b)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not same" << endl;
    }
    return 0; // destructor is being called
}
