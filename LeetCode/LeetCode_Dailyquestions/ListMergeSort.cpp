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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    vector<int> ans;
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;
    while (temp1 != NULL and temp2 != NULL)
    {
        if (temp1->val <= temp2->val)
        {
            ans.push_back(temp1->val);
            temp1 = temp1->next;
        }
        else
        {
            ans.push_back(temp2->val);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        ans.push_back(temp1->val);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        ans.push_back(temp2->val);
        temp2 = temp2->next;
    }
    ListNode *newHead;
    ListNode *temp = new ListNode(0);
    if (temp1->val <= temp2->val)
    {
        temp = temp1;
    }
    else
    {
        temp = temp2;
    }
    newHead = temp;
    temp = temp->next;
    int l = ans.size();
    for (int i = 1; i < l; i++)
    {
        temp->val = ans[i];
        temp = temp->next;
    }
    return newHead;
}
