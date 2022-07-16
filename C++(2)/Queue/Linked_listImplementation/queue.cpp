#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    node *front;
    node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        {
            back = n;
            front = n;
        }
        back->next = n;
        back = n;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
        }
        node *toDelete = front;
        front = front->next;
        delete toDelete;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "NO element in queue" << endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Queue q;
    for (int i = 1; i <= 4; i++)
    {
        q.push(i);
    }
    for (int i = 1; i <= 4; i++)
    {
        cout << q.peek() << endl;
        q.pop();
    }
    cout << q.empty() << endl;
}