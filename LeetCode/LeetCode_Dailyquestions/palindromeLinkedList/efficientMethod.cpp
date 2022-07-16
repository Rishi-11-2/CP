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
bool isPalindrome(ListNode *head)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ListNode *fast = head, *prev = NULL, *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        head->next = prev;
        prev = head;
        head = slow;
    }
    if (fast)
        slow = slow->next;
    while (prev && slow)
    {
        if (prev->val != slow->val)
            return false;
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}