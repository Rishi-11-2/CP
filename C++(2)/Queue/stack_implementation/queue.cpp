#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) // time complexity : O(1)
    {
        s1.push(x);
    }
    int pop() // time complexity :O(n)
    {
        if (s1.empty() and s2.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    bool empty()
    {
        if (s1.empty() and s2.empty())
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