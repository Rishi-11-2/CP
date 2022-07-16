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
bool detectCycle(node *&head) // detect cycle by Floyd's Algorithm i.e by fast and slow pointer
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
void makeCycle(node *&head, int pos) // make cycle
{
    node *temp = head;
    node *startHead;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startHead = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startHead;
}

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;

    } while (slow != fast);
    //  way to remove the cycle at head itself
    if (fast == head)
    {
        while (slow->next != head)
        {
            slow = slow->next;
        }
        slow->next = NULL;
        return;
    }

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

void insertAtTail(node *&head, int val)
{
    node *temp = head;
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    if (head == NULL)
        return;
    node *&temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    makeCycle(head, 1);
    cout << detectCycle(head) << endl;
    removeCycle(head);
    cout << detectCycle(head) << endl;
    display(head);
}