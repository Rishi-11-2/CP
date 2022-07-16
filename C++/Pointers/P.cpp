#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 10;
    int *aptr = &a;
    cout << *aptr << endl;
    *aptr = 20;
    cout << a << endl;
    aptr++;
    cout << aptr << endl;
    int arr[] = {10, 20, 30};
    cout << *arr << endl;
    int *ptr = arr;
    for (int i = 0; i < 3; i++)
    {
        cout << *ptr << endl;
        ptr++;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << *(arr + i) << endl; // array is an indexing pointer. when arr is incresed by one the index that it refers to next index//
    }
    int **q = &ptr;
    cout << *q << endl;  // prints the value of p
    cout << **q << endl; // prints the value of a
}