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
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    int pairSum(ListNode *head)
    {
        if (!head->next->next)
            return head->val + head->next->val;
        ListNode *slow = head, *fast = head;
        while (fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;
        int mx = INT_MIN;
        stack<int> st;
        fast = head;
        while (fast != slow)
        {
            st.push(fast->val);
            fast = fast->next;
        }
        while (slow)
        {
            mx = max(slow->val + st.top(), mx);
            slow = slow->next;
            st.pop();
        }
        return mx;
    }
};