#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    // another way
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    v.pop_back();          // 1 2
    vector<int> v2(3, 50); // 50 ,50 ,50
    swap(v, v2);
    cout << endl;
    for (auto it : v)
    {
        cout << it << " ";
    }
    v2.push_back(0);
    sort(v2.begin(), v2.end());
    cout << endl;
    for (auto it : v2)
    {
        cout << it << " ";
    }
}