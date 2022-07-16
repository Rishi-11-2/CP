#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1;

public:
    void push(int x) // time complexity : O(1)
    {
        s1.push(x);
    }
    int pop() // implementing queue pop structure using call stack
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }
        int item = pop();
        s1.push(x);
        return item;
    }
    bool empty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};
int32_t main()
{
    Queue q;
    for (int i = 1; i <= 4; i++)
    {
        q.push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << q.pop() << endl;
    }
}