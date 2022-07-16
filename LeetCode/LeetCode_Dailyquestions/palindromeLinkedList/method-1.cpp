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
    ListNode *temp = head;
    string s = "";
    while (temp != NULL)
    {
        int val = temp->val;
        temp = temp->next;
        s += val;
    }
    string z = s;
    reverse(s.begin(), s.end());

    if (z == s)
    {
        return true;
    }
    return false;
}