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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *curr = l1;
    string s1 = "";
    string s2 = "";

    while (curr != NULL)
    {
        s1 += (curr->val);
        curr = curr->next;
    }

    curr = l2;

    while (curr != NULL)
    {
        s2 += (curr->val);
        curr = curr->next;
    }

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string s = to_string(stoi(s1) + stoi(s2));
    reverse(s.begin(), s.end());

    ListNode *temp = new ListNode(s[0]);
    ListNode *newH = temp;
    int i = 1;

    while (i < s.length())
    {
        ListNode *p = new ListNode(s[i]);
        i++;
        temp->next = p;
        temp = p;
    }
    temp->next = NULL;
    return newH;
}