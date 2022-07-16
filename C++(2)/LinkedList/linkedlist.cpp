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
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n; // doing this so that the head points to 'n'
}
void insertAtTail(node *&head, int val) // here we are taking head by reference
{

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void deleteAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;
    delete toDelete; // if we dont delete than memory leak can happen
}
void deletion(node *&head, int val)
{
    if (head == NULL) // checking whether the Link List is empty or not
    {
        return;
    }
    if (head->next == NULL) // checking whether there is a single element in the Linked List or not
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *toD = temp->next;
    temp->next = temp->next->next;
    delete toD;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    display(head);
    // cout << search(head, 2) << endl;
    // cout << search(head, 5) << endl;
    // deletion(head, 3);
    deleteAtHead(head);
    display(head);

    return 0;
}