#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *temp = head;
        int l = 0;
        while (temp->next != NULL)
        {
            l++;
            temp = temp->next;
        }
        int arr[l + 1];
        temp = head;
        int i = 0;
        while (temp != NULL)
        {
            arr[i++] = temp->val;
            temp = temp->next;
        }
        i = k;
        int j = l - k + 1;
        while (i != j)
        {
            swap(arr[i++], arr[j--]);
        }
        ListNode *newHead = head;
        ListNode *temp1 = head;
        i = 0;
        while (temp1 != NULL)
        {
            temp1->val = arr[i++];
            temp1 = temp1->next;
        }
        return newHead;
    }
};