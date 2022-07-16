#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 10;
    int *p = new int();
    *p = 10;
    delete (p);
    p = new int[4];
    for (int i = 0; i < 4; i++)
    {
        p[i] = i;
        cout << p[i];
    }
    p = new int[5];//changing the size of array.THIS variable is stored in heap(dynamic memory allocation)
    
    for (int i = 0; i < 5; i++)
    {
        p[i] = i;
        cout << p[i];
    }
    delete[] p;
    p = NULL;
}