#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int data)
    {
        val = data;
        next = NULL;
    }
};
int length(node *head)
{
    node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
void insertAtTail(node *&head, int val)
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
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
node *merge(node *&head1, node *&head2)
{ // merge sorting two linked list . it is the gist of this program
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *n = new node(0);
    node *newHead = n;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->val < ptr2->val)
        {
            n->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            n->next = ptr2;
            ptr2 = ptr2->next;
        }
        n = n->next;
    }
    while (ptr1 != NULL)
    {
        n->next = ptr1;
        ptr1 = ptr1->next;
        n = n->next;
    }
    while (ptr2 != NULL)
    {
        n->next = ptr2;
        ptr2 = ptr2->next;
        n = n->next;
    }
    return newHead->next;
}
node *mergeRecursive(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *result;
    if (head1->val < head2->val)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {2, 3, 6};
    for (int i = 0; i < 4; i++)
    {
        insertAtTail(head1, arr1[i]);
    }
    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
    {
        insertAtTail(head2, arr2[i]);
    }
    display(head1);
    display(head2);
    display(mergeRecursive(head1, head2));
}

// Time Complexity:O(m+n)