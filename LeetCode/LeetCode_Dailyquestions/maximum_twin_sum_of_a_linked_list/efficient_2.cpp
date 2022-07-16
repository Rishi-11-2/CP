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

int pairSum(ListNode *head)
{
    int count = 0, i = 0, maximum = INT_MIN;
    ListNode *temp = head;
    stack<int> s;

    while (temp)
    {
        s.push(temp->val);
        temp = temp->next;
        ++count;
    }

    temp = head;

    while (i < count / 2)
    {
        maximum = max(maximum, temp->val + s.top());
        temp = temp->next;
        s.pop();
        i++;
    }
    return maximum;
}
