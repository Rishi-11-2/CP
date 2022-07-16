#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    for (auto it : dq)
    {
        cout << it << " ";
    }
    cout << endl;
    dq.pop_back();
    dq.pop_front();
    for (auto it : dq)
    {
        cout << it << " ";
    }
}